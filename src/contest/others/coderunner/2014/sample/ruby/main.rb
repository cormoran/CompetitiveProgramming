require 'open-uri'

def query(url)
  res = open(url)
  res.string
end

token  = "xxxxxxx"

2.times.each do |i|
  url    = "http://example.com/api01?token=#{token}"
  result = query(url)
  puts result

  sleep 1
end