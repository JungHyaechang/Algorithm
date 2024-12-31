using namespace std;

long long solution(int price, int money, int count)
{
    long long pay = 0;
    
    for(int i = 1; i <= count; i++){
        pay += price*i;
    }
    
    if(money >= pay){
        return 0;
    } 
    else {
        return pay - money;
    }
}