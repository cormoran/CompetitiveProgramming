import glob, subprocess, sys, os, logging, subprocess, re, json
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logger.addHandler(logging.StreamHandler(sys.stderr))

def output_subprocess_result(res):
    if len(res.stdout) > 0:
        for line in res.stdout.decode('utf-8').split("\n"):
            print("\t" + line, file=sys.stdout)
    if len(res.stderr) > 0:
        for line in res.stderr.decode('utf-8').split("\n"):
            print("\t" + line, file=sys.stderr)

def compile(test):
    logger.debug("COMPILE")
    command = ['g++-6', '-Wall', '-O3', '-std=c++14', '-fdiagnostics-color=always', '-I', '/Users/ukai/Program/src/github.com/cormoran/CompetitiveProgramming/src/library', test]
    res = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output_subprocess_result(res)
    if res.returncode != 0:
        output_subprocess_result(res)
        logger.error("❌  failed to compile")
        return False
    return True

def get_problem_url(test):
    with open(test) as f:
        line = f.readline()
        match = re.match("\s*//\s*url\s*:\s*(.*)", line)
        if match:
            return match.group(1), True
    logger.error("❌  failed to parse problem url")
    return "", False

def download_test(test, url):
    logger.debug("DOWNLOAD")
    prefix= os.path.basename(test)
    command = ['/Users/ukai/local/bin/oj', 'dl', url, '-f', 'test_case/' + prefix + '.%i.%e', '--silent']
    res = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    # output_subprocess_result(res)
    if res.returncode != 0:
        output_subprocess_result(res)
        logger.error("❌  failed to download")
        return False
    return True

def run_test(test, url):
    logger.debug("TEST")
    prefix= os.path.basename(test)
    command = ['/Users/ukai/local/bin/oj', 'test', '-f', 'test_case/' + prefix + ".%s.%e", '--silent']
    res = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if res.returncode != 0:
        output_subprocess_result(res)
        logger.error("❌  failed to test")
        return False
    ac = res.stderr.decode('utf-8').find("success") != -1
    return ac

def to_lib_filename(test):
    match = re.match("test_([^\.]*)", os.path.basename(test))
    if match:
        return match.group(1) + ".hpp"
    return test

def group_tests(test_and_url):
    res = {}
    for test, url in test_and_url:
        name = to_lib_filename(test)
        if not name in res:
            res[name] = []
        res[name].append(url)
    return res

def main(args):
    """
    1. write library
        ex) foo_bar.hpp
    2. write test
        test for foo_bar.hpp is test_foo_bar.*.cpp
    """
    all_cnt, ac, wa, no = 0, 0, 0, 0
    success, wrong, failed = [], [], [] # list of (test, url)

    for test in glob.glob('**/test_*.cpp',recursive=True):
        logger.info(test)
        all_cnt += 1
        ok = compile(test)
        if not ok:
            no += 1
            failed.append((test, ""))
            continue
        url, found = get_problem_url(test)
        if not found:
            no += 1
            failed.append((test, url))
            continue
        if not download_test(test, url):
            no += 1
            failed.append((test, url))
            continue
        res = run_test(test, url)
        if res:
            success.append((test, url))
            ac += 1
        else:
            wrong.append((test, url))
            wa += 1
        logger.info("✅  {}".format(test))

    logger.info("""
    🏁   ____  _____ ____  _   _ _   _____   🏁
    🏁  |  _ \| ____/ ___|| | | | | |_   _|  🏁
    🏁  | |_) |  _| \___ \| | | | |   | |    🏁
    🏁  |  _ <| |___ ___) | |_| | |___| |    🏁
    🏁  |_| \_\_____|____/ \___/|_____|_|    🏁
    🏁                                       🏁
    """)
    logger.info("⭕️  sucess")
    logger.info('\n'.join([t + ": " + u for t, u in success]))
    logger.info("❌  wrong")
    logger.info('\n'.join([t + ": " + u for t, u in wrong]))
    logger.info("⚠️  failed to run")
    logger.info('\n'.join([t + ": " + u for t, u in failed]))
    print(json.dumps({
        "success": group_tests(success),
        "wrong": group_tests(wrong),
        "fail": group_tests(failed),
    }, indent=4))

if __name__ == '__main__':
    main(args=sys.argv)