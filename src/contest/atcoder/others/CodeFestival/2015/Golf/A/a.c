n,f,s,t;
main(){
    scanf("%d",&n);
    f=2*n;
    while(n--){
        scanf("%d",&t);
        f*=s?1:t;
        s+=t;
    }
    puts(s<f?"Pass":"Fail");
}

