#include<iostream>
#include<string>
#include"interface.hpp"
using namespace std;

bool judge_parentheses_Exist(string a){
    int a_len = a.length();
    bool flag_for_Exist =false;
    for (int i = 0;i<a_len;i++){
        if(a[i]=='('){
            flag_for_Exist=true;
        }
    }
    return flag_for_Exist;
}

bool judge_parenthesesPairs_Right(string a){
    int a_len = a.length();
    int count_leftParenthesees = 0;
    int count_rightParentheses = 0;
    bool flag_for_Right = true;
    for(int i=0;i<a_len;i++){
        if(a[i]=='('){
            count_leftParenthesees++;
        }else if(a[i]==')'){
            count_rightParentheses++;
        }
    }
    if(count_leftParenthesees!=count_rightParentheses){
        flag_for_Right=false;
    }
    return flag_for_Right;
}
//
//
bool judge_negativeSign_Exist(string a){
    int a_len = a.length();
    bool flag_Exist = false;
    for(int i =0;i<a_len;i++){
        if(a[i]=='-'){
            flag_Exist=true;
        }
    }
    return flag_Exist;
}

bool judge_negativeSign_Right(string a){
    int a_len = a.length();
    bool flag_Right = true;
    if(a[a_len-1]=='-'){
        flag_Right = false;
    }else{
        for(int i=0;i<a_len;i++){
            if(a[i]=='-'){
                if((a[i-1]!='-' && a[i-1]!='+' && a[i-1]!='.')&&
                   ((a[i+1]>='0' && a[i+1]<='9')||(a[i+1]=='('))){
                    ;
                }else{
                    flag_Right = false;
                }
            }
        }
    }
    return flag_Right;
}
//
//
bool judge_point_Exist(string a){
    int a_len = a.length();
    bool flag_Exist = false;
    for(int i =0;i<a_len;i++){
        if(a[i]=='.'){
            flag_Exist=true;
        }
    }
    return flag_Exist;
}

bool judge_point_Right(string a){
    int a_len = a.length();
    bool flag_Right = true;
    if(a[0]=='.'||a[a_len-1]=='.'){
        flag_Right = false;
    }else{
        for(int i=0;i<a_len;i++){
            if(a[i]=='.'){
                if((a[i-1]>='0' && a[i-1]<='9')&&(a[i+1]>='0' && a[i+1]<='9')){
                    ;
                }else{
                    flag_Right = false;
                }
            }
        }
    }
    return flag_Right;
}
//
//
bool judge_e_Exist(string a){
    int a_len = a.length();
    bool flag_Exist = false;
    for(int i =0;i<a_len;i++){
        if(a[i]=='e'){
            flag_Exist=true;
        }
    }
    return flag_Exist;
}

bool judge_e_Right(string a){
    int a_len = a.length();
    bool flag_Right = true;
    if(a[0]=='e'||a[a_len-1]=='e'){
        flag_Right = false;
    }else{
        for(int i=0;i<a_len;i++){
            if(a[i]=='e'){
                if(((a[i-1]>='0' && a[i-1]<='9')&&(a[i+1]>='0' && a[i+1]<='9'))||
                   ((a[i-1]>='0' && a[i-1]<='9')&&(a[i+1]=='-')&&(a[i+2]>='0' && a[i+2]<='9'))){
                }else{
                    flag_Right = false;
                }
            }
        }
    }
    return flag_Right;
}
//
//
bool judge_function_Exist(string a){
    int a_len = a.length();
    bool flag_Exist = false;
    for(int i=0;i<a_len;i++){
        if(a[i]=='s' && i<a_len-4){
            if(a[i+1]=='q' && a[i+2]=='r' && a[i+3]=='t'){
                flag_Exist=true;
            }
        }
        if(a[i]=='e' && i<a_len-4){
            if(a[i+1]=='x' && a[i+2]=='p'){
                flag_Exist=true;
            }
        }
        if(a[i]=='a' && i<a_len-4){
            if(a[i+1]=='b' && a[i+2]=='s'){
                flag_Exist=true;
            }
        }
        if(a[i]=='p' && i<a_len-4){
            if(a[i+1]=='o' && a[i+2]=='w'){
                flag_Exist=true;
            }
        }
    }
    return flag_Exist;
}

bool judge_function_Right(string a){
    int a_len = a.length();
    bool flag_Right = true;
    for(int i=0;i<a_len;i++){
        if(a[i]=='s' && i<a_len-5){
            if(a[i+1]=='q' && a[i+2]=='r' && a[i+3]=='t' && (a[i+5]=='-' || a[i+5]==')')){
                flag_Right = false;
            }else if(a[i+1]=='q' && a[i+2]=='r' && a[i+3]=='t'){
                i+=4;
            }else{
                flag_Right = false;
            }
        }
        if(a[i]=='a' && i<a_len-4){
            if(a[i+1]=='b' && a[i+2]=='s' && (a[i+4]==')')){
                flag_Right=false;
            }else if(a[i+1]=='b' && a[i+2]=='s'){
                i+=3;
            }else{
                flag_Right=false;
            }
        }
    }
    return flag_Right;
}
//
//
bool judge_twoPointOre(string a){
    int a_len = a.length();
    int position[a_len]={};
    position[0]=0;
    int count=1;
    bool flag_singlePoint = true;
    bool flag_singleE = true;
    bool flag_sequence = true;
    for(int i=0;i<a_len;i++){
        if(a[i]=='(' || a[i]==')' || a[i]=='+' || a[i]=='-' || a[i]=='*'){
            position[count]=i;
            count++;
        }
    }
    position[count]=a_len-1;
    for(int i=0;i<count;i++){
        int point=0;
        int e=0;
        bool e_exist = false;
        for(int j=position[i];j<position[i+1];j++){
            if(a[j]=='e'){
                e++;
                e_exist = true;
            }else if(a[j]=='.' && e_exist == false){
                point++;
            }else if(a[j]=='.' && e_exist == true){
                flag_sequence = false;
            }
            if(point>1){
                flag_singlePoint = false;
            }
            if(e>1){
                flag_singleE = false;
            }
        }
    }
    if(flag_singleE && flag_singlePoint && flag_sequence){
        return true;
    }else{
        return false;
    }
}
//
bool judge_inputFormula_valid(string a){
    int a_len = a.length();
    bool flag_parentheses = true;
    bool flag_negative = true;
    bool flag_point = true;
    bool flag_e = true;
    bool flag_function = true;
    bool flag_pre_valid = true;
    bool flag_valid = true;

    if(judge_parentheses_Exist(a)){
        if(judge_parenthesesPairs_Right(a)){
            ;
        }else{
            flag_parentheses = false;
        }
    }
    if(judge_negativeSign_Exist(a)){
        if(judge_negativeSign_Right(a)){
            ;
        }else{
            flag_negative = false;
        }
    }
    if(judge_point_Exist(a)){
        if(judge_point_Right(a)){
            ;
        }else{
            flag_point = false;
        }
        if(judge_twoPointOre(a)){
            ;
        }else{
            flag_point = false;
        }
    }
    if(judge_e_Exist(a)){
        if(judge_e_Right(a)){
            ;
        }else{
            flag_e = false;
        }
        if(judge_twoPointOre(a)){
            ;
        }else{
            flag_point = false;
        }
    }
    if(judge_function_Exist(a)){
        if(judge_function_Right(a)){
            ;
        }else{
            flag_function = false;
        }
    }
    for(int i =0; i<a_len;i++){
        if(a[i]=='s' && i<a_len-5){
            if(a[i+1]=='q' && a[i+2]=='r' && a[i+3]=='t'){
                i+=4;
            }
        }
        if(a[i]=='a' && i<a_len-4){
            if(a[i+1]=='b' && a[i+2]=='s'){
                i+=3;
            }
        }
        if((a[i]!='.' && a[i]!='e' && a[i]!='+' && a[i]!='*' && a[i]!='-' && a[i]!='(' && a[i]!=')') && 
           (a[i]<'0' || a[i]>'9')){
            flag_pre_valid=false;
        }
    }
    if(flag_e && flag_function && flag_negative && flag_point && flag_pre_valid && flag_parentheses){
        ;
    }else{
        flag_valid = false;
    }
    return flag_valid;
}

bool judge_is_formula(string a){
    int a_len = a.length();
    bool is_formula = false;
    for(int i=1;i<a_len;i++){
        if(a[i]=='*' || a[i]=='-' || a[i]=='+'){
            is_formula = true;
            break;
        }
    }
    return is_formula;
}
