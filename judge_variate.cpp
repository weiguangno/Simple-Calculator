#include<iostream>
#include<string>
#include"interface.hpp"
using namespace std;

bool judge_equalSign_Exist(string a){
    int a_len = a.length();
    bool flag_Exist = false;
    for(int i=0;i<a_len;i++){
        if(a[i]=='='){
            flag_Exist=true;
        }
    }
    return flag_Exist;
}

bool judge_equalSign_Right(string a){
    int a_len = a.length();
    bool flag_Right = true;
    if(a[0]=='='||a[a_len-1]=='='){
        flag_Right=false;
    }else{
        for(int i=0;i<a_len;i++){
            if(a[i]=='='){
                if(((a[i-1]>='a'&&a[i-1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'))&&(a[i+1]>='0'&&a[i+1]<='9')){
                    ;
                }else{
                    flag_Right = false;
                }
            }
        }
    }
    return flag_Right;
}

bool judge_inputEqualSign_valid(string a){
    int a_len = a.length();
    bool flag_valid = true;
    bool before_equalSign = true;
    bool flag_point = true;
    bool flag_e = true;
    for(int i=0;i<a_len;i++){
        if(a[i]=='='){
            before_equalSign = false;
            i++;
        }
        if(((a[i]<'a' || a[i]>'z')&&(a[i]<'A' || a[i]>'Z')) && before_equalSign==true){
            flag_valid = false;
        }
        if(a[i]=='.' && before_equalSign == false){
            if(i==a_len-1){
                flag_valid = false;
            }
            if(a[i-1]<'0'||a[i-1]>'9'){
                flag_valid = false;
            }
            if(flag_point==false){
                flag_valid = false;
            }
            flag_point = false;
        }
        if(a[i]=='e' && before_equalSign == false){
            if(i==a_len-1){
                flag_valid = false;
            }
            if(a[i-1]<'0'||a[i-1]>'9'){
                flag_valid = false;
            }
            if(flag_e==false){
                flag_valid = false;
            }
            flag_e = false;
        }
        if((a[i]!='.' && a[i]!='e')&&(a[i]<'0'||a[i]>'9')&&before_equalSign==false){
            flag_valid = false;
        }
    }
    for(int i=0;i<a_len;i++){
        if(a_len>4){
            if(a[0]=='a' && a[1]=='b' && a[2]=='s'){
                flag_valid = false;
            }else if(a[0]=='s' && a[1]=='q' && a[2]=='r' && a[i]=='t'){
                flag_valid = false;
            }
        }
    }
    return flag_valid;
}
