bool is_mult(int,int);


bool is_mult(int a, int b){

    if(a%b == 0){
        return true;
    }
    else{
        return false;
    }

}


int main(){

    bool pippo;
    
    int v1,v2;

    cin >> v1 >> v2;

    pippo = is_mult(v1,v2);





}

