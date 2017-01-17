n,q,p[100001]={};
a,b,c;
P(x){return p[x]?P(x):x;}
M(x,y){}
main(){
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d%d%d",&a,&b,&c);
        if(a)puts(P(b)-P(c)?"YES":"NO");
        else if(P(b)-P(c))?a:p[b]=c;
    }
}
