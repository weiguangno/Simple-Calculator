#include<iostream>
#include"interface.hpp"
using namespace std;

//Math.Method
string sqrt(string str){
    string upperbound = "100.00";
    string lowerbound = "5.00";
    string square_upperbound = "10000.00";
    string square_lowerbound = "25.00";
    string middle = "52.50";
    string square_middle = "2756.25";
    bool intheBound = false;
    string accept_difference ="0.000000000000000001";
    if(judge_point_Exist(str)==false){
        str=str+".00";
    }
    string minus_number = "";
    string c = "";
    bool flag_for_difference = false;
    bool flag_for_smallDifference = false;
    if(compare_leftToright_value(str,square_middle)==1){
        minus_number = "-"+square_middle;
        c = ADD_FLOAT(str,minus_number);
    }else if(compare_leftToright_value(square_middle,str)==1){
        minus_number = "-"+str;
        c = ADD_FLOAT(square_middle,minus_number);
    }else{
        c="0.00";
    }
    if(compare_leftToright_value(accept_difference,c)==1){
        flag_for_difference=true;
    }else{
        flag_for_difference=false;
    }
    while(flag_for_difference == false){
        if(compare_leftToright_value(square_lowerbound,str)==1){
            upperbound = cut_half(upperbound);
            lowerbound = cut_half(lowerbound);
            middle = cut_half(ADD_FLOAT(upperbound,lowerbound));
            square_lowerbound = MUL_FlOAT(lowerbound,lowerbound);
            square_upperbound = MUL_FlOAT(upperbound,upperbound);
            square_middle = MUL_FlOAT(middle,middle);
        }else if(compare_leftToright_value(str,square_upperbound)==1){
            upperbound = ADD_FLOAT(upperbound,upperbound);
            lowerbound = ADD_FLOAT(lowerbound,lowerbound);
            middle = cut_half(ADD_FLOAT(upperbound,lowerbound));
            square_lowerbound = MUL_FlOAT(lowerbound,lowerbound);
            square_upperbound = MUL_FlOAT(upperbound,upperbound);
            square_middle = MUL_FlOAT(middle,middle);
        }else if(compare_leftToright_value(str,square_upperbound)==0){
            str = upperbound;
            break;
        }else if(compare_leftToright_value(str,square_upperbound)==0){
            str = lowerbound;
            break;    
        }else{
            flag_for_smallDifference = true;
            if(compare_leftToright_value(square_middle,str)==1){
                upperbound = middle;
                middle = cut_half(ADD_FLOAT(upperbound,lowerbound));
                square_lowerbound = MUL_FlOAT(lowerbound,lowerbound);
                square_middle = MUL_FlOAT(middle,middle);
                square_upperbound = MUL_FlOAT(upperbound,upperbound);
                if(compare_leftToright_value(str,square_middle)==1){
                    minus_number = "-"+square_middle;
                    c = ADD_FLOAT(str,minus_number);
                }else if(compare_leftToright_value(square_middle,str)==1){
                    minus_number = "-"+str;
                    c = ADD_FLOAT(square_middle,minus_number);
                }else{
                    c="0.00";
                }
                if(compare_leftToright_value(accept_difference,c)==1){
                    flag_for_difference=true;
                }else{
                    flag_for_difference=false;
                }
            }else if(compare_leftToright_value(square_middle,str)==-1 || compare_leftToright_value(square_middle,str)==0){
                lowerbound = middle;
                middle = cut_half(ADD_FLOAT(upperbound,lowerbound));
                square_lowerbound = MUL_FlOAT(lowerbound,lowerbound);
                square_middle = MUL_FlOAT(middle,middle);
                square_upperbound = MUL_FlOAT(upperbound,upperbound);
                if(compare_leftToright_value(str,square_middle)==1){
                    minus_number = "-"+square_middle;
                    c = ADD_FLOAT(str,minus_number);
                }else if(compare_leftToright_value(square_middle,str)==1){
                    minus_number = "-"+str;
                    c = ADD_FLOAT(square_middle,minus_number);
                }else{
                    c="0.00";
                }
                if(compare_leftToright_value(accept_difference,c)==1){
                    flag_for_difference=true;
                }else{
                    flag_for_difference=false;
                }
            }
        }
    }
    if(flag_for_smallDifference == true){
        str=middle;
    }
    return str;
}

string abs(string a){
    int a_len = a.length();
    if(a[0]=='-'){
        a.erase(0,1);
    }
    return a;
}


//basic function
void split_vatiateAndValue(string* input,string* variate,string* value,int index){
    int length = input[index].length();
    int equal_position = 0;
    for(int i=0;i<length;i++){
        if(input[index][i]=='='){
            equal_position = i;
        }
    }
    variate[index]=input[index].substr(0,equal_position);
    value[index]=input[index].substr(equal_position+1);
}

string replace_formula(string* input,string* variate,string* value,int record_i,int input_i){
    for(int i =0;i<record_i;i++){
        int position = input[input_i].find(variate[i]);
        if(position == input[input_i].npos){
            continue;
        }
        while((input[input_i][position]=='s' && input[input_i][position+1]=='q' && input[input_i][position+2]=='r' && input[input_i][position+3]=='t')||
           (input[input_i][position]=='a' && input[input_i][position+1]=='b' && input[input_i][position+2]=='s')){
            position = input[input_i].find(variate[i],position+1);
        }
        while(position>=0 && position<=input[input_i].length()){
            input[input_i].replace(position,variate[i].length(),value[i]);
            position = input[input_i].find(variate[i]);
            while((input[input_i][position]=='s' && input[input_i][position+1]=='q' && input[input_i][position+2]=='r' && input[input_i][position+3]=='t')||
                  (input[input_i][position]=='a' && input[input_i][position+1]=='b' && input[input_i][position+2]=='s')){
                position = input[input_i].find(variate[i],position+1);
            }
            if(position == input[input_i].npos){
                break;
            }   
        }
    }
    return input[input_i];
}

void sort_variate(string* variate,string* value,int record_i){
    int size_variate[record_i]={};
    int max_index=0;
    for(int i=0;i<record_i;i++){
        size_variate[i]=variate[i].length();
    }
    for(int i =0;i<record_i-1;i++){
        max_index=i;
        for(int j=i+1;j<record_i;j++){
            if(size_variate[max_index]<size_variate[j]){
                max_index=j;
            }
        }
        string t="";
        t = variate[i]; variate[i] = variate[max_index]; variate[max_index] = t;
        t = value[i]; value[i] = value[max_index]; value[max_index] = t;
    }
}

string calculate_additionAndmultiplication(string a){
    int split_position[a.length()]={};
    string split_data[a.length()]={};
    int count_operation = 0;
    int count_data = 0;


    for(int i =1;i<a.length();i++){
        if(a[i]=='+' || a[i]=='*'){
            split_position[count_operation] = i;
            count_operation++;
            continue;
        }else if(a[i]=='-' && a[i-1]=='*'){
            i++;
        }else if(a[i]=='-' && a[i-1]=='e'){
            i++;
        }else if(a[i]=='-'){
            split_position[count_operation] = i;
            count_operation++;
        }
    }
    split_data[0]=a.substr(0,split_position[0]);
    count_data++;
    for(int i=0;i<count_operation-1;i++){
        if(a[split_position[i]]=='-'){
            split_data[count_data]=a.substr(split_position[i],split_position[i+1]-split_position[i]);
        }else{
            split_data[count_data]=a.substr(split_position[i]+1,split_position[i+1]-split_position[i]-1);
        }
        count_data++;
    }

    if(a[split_position[count_operation-1]]=='-'){
        split_data[count_data]=a.substr(split_position[count_operation-1],a.length()-split_position[count_operation-1]);
    }else{
        split_data[count_data]=a.substr(split_position[count_operation-1]+1,a.length()-split_position[count_operation-1]-1);
    }
    count_data++;

    bool multiplication_exist = false;
    int record_multiplicationPosition = 0;
    for(int i=0;i<count_operation;i++){
        if(a[split_position[i]]=='*'){
            multiplication_exist = true;
            record_multiplicationPosition = i;
            break;
        }
    }
    while(multiplication_exist==true){
        if((judge_point_Exist(split_data[record_multiplicationPosition]) && 
            judge_e_Exist(split_data[record_multiplicationPosition])==false)&&
           (judge_point_Exist(split_data[record_multiplicationPosition+1]) && 
            judge_e_Exist(split_data[record_multiplicationPosition+1])==false)
            ){
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition]) && 
                  judge_e_Exist(split_data[record_multiplicationPosition])==false)&&
                 (judge_e_Exist(split_data[record_multiplicationPosition+1]))){
            split_data[record_multiplicationPosition+1]=change_form_tofloat(split_data[record_multiplicationPosition+1]);
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_e_Exist(split_data[record_multiplicationPosition]))&&
                 (judge_point_Exist(split_data[record_multiplicationPosition+1]) && 
                  judge_e_Exist(split_data[record_multiplicationPosition+1])==false)){
        }else if((judge_e_Exist(split_data[record_multiplicationPosition]))&&
                 (judge_e_Exist(split_data[record_multiplicationPosition+1]))){
            split_data[record_multiplicationPosition]=change_form_tofloat(split_data[record_multiplicationPosition]);
            split_data[record_multiplicationPosition+1]=change_form_tofloat(split_data[record_multiplicationPosition+1]);
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition])==false)&&
                 (judge_e_Exist(split_data[record_multiplicationPosition+1]))){
            split_data[record_multiplicationPosition]=split_data[record_multiplicationPosition]+".00";
            split_data[record_multiplicationPosition+1]=change_form_tofloat(split_data[record_multiplicationPosition+1]);
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition])==false)&&
                 (judge_point_Exist(split_data[record_multiplicationPosition+1]) && 
                  judge_e_Exist(split_data[record_multiplicationPosition+1])==false)){
            split_data[record_multiplicationPosition]=split_data[record_multiplicationPosition]+".00";
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition+1])==false)&&
                 (judge_e_Exist(split_data[record_multiplicationPosition]))){
            split_data[record_multiplicationPosition+1]=split_data[record_multiplicationPosition+1]+".00";
            split_data[record_multiplicationPosition]=change_form_tofloat(split_data[record_multiplicationPosition]);
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition+1])==false)&&
                 (judge_point_Exist(split_data[record_multiplicationPosition]) && 
                  judge_e_Exist(split_data[record_multiplicationPosition])==false)){
            split_data[record_multiplicationPosition+1]=split_data[record_multiplicationPosition+1]+".00";
            split_data[record_multiplicationPosition]=MUL_FlOAT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }else if((judge_point_Exist(split_data[record_multiplicationPosition])==false)&&
                 (judge_point_Exist(split_data[record_multiplicationPosition+1])==false)){
            split_data[record_multiplicationPosition]=split_data[record_multiplicationPosition];
            split_data[record_multiplicationPosition+1]=split_data[record_multiplicationPosition+1];
            split_data[record_multiplicationPosition]=MUL_INT(split_data[record_multiplicationPosition],split_data[record_multiplicationPosition+1]);
        }

        for(int i=record_multiplicationPosition;i<count_operation-1;i++){
            split_position[i]=split_position[i+1];
        }
        for(int i=record_multiplicationPosition+1;i<count_data-1;i++){
            split_data[i]=split_data[i+1];
        }


        count_operation--;
        count_data--;
        multiplication_exist = false;
        record_multiplicationPosition = 0;
        for(int i=0;i<count_operation;i++){
           if(a[split_position[i]]=='*'){
                multiplication_exist = true;
                record_multiplicationPosition = i;
                break;
            } 
        }
    }




    bool addition_exist = false;
    int record_additionPosition = 0;
    for(int i=0;i<count_operation;i++){
        if(a[split_position[i]]=='+' || a[split_position[i]]=='-'){
            addition_exist = true;
            break;
        }
    }


    while(addition_exist==true){
        string aa = split_data[0];
        string bb = split_data[1];


        if((judge_point_Exist(aa) && judge_e_Exist(aa)==false)&&
           (judge_point_Exist(bb) && judge_e_Exist(bb)==false)){
            split_data[record_additionPosition]=ADD_FLOAT(aa,bb);
        }else if((judge_point_Exist(aa) && judge_e_Exist(aa)==false)&&
                 (judge_e_Exist(bb))){
            split_data[0]=ADD_FLOAT(aa,change_form_tofloat(bb).data());
        }else if((judge_e_Exist(aa))&&
                 (judge_point_Exist(bb) && judge_e_Exist(bb)==false)){
            split_data[record_additionPosition]=change_form_tofloat(aa);
            split_data[record_additionPosition]=ADD_FLOAT(split_data[record_additionPosition],bb);
        }else if((judge_e_Exist(aa))&&
                 (judge_e_Exist(bb))){
            split_data[record_additionPosition]=change_form_tofloat(aa);
            split_data[record_additionPosition+1]=change_form_tofloat(bb);
            split_data[record_additionPosition]=ADD_FLOAT(split_data[record_additionPosition],split_data[record_additionPosition+1]);
        }else if((judge_point_Exist(aa)==false)&&
                 (judge_e_Exist(bb))){
            split_data[record_additionPosition]=aa+".00";
            split_data[record_additionPosition+1]=change_form_tofloat(bb);
            split_data[record_additionPosition]=ADD_FLOAT(split_data[record_additionPosition],split_data[record_additionPosition+1]);
        }else if((judge_point_Exist(aa)==false)&&
                 (judge_point_Exist(bb) && judge_e_Exist(bb)==false)){
            split_data[record_additionPosition]=aa+".00";
            split_data[record_additionPosition]=ADD_FLOAT(split_data[record_additionPosition],bb);
        }else if((judge_point_Exist(bb)==false)&&
                 (judge_e_Exist(aa))){
            split_data[record_additionPosition+1]=bb+".00";
            split_data[record_additionPosition]=change_form_tofloat(aa);
            split_data[record_additionPosition]=ADD_FLOAT(split_data[record_additionPosition],split_data[record_additionPosition+1]);
        }else if((judge_point_Exist(bb)==false)&&
                 (judge_point_Exist(aa) && judge_e_Exist(aa)==false)){
            split_data[record_additionPosition+1]=bb+".00";
            split_data[0]=ADD_FLOAT(aa,split_data[record_additionPosition+1]);
        }else if((judge_point_Exist(aa)==false)&&
                 (judge_point_Exist(bb)==false)){
            split_data[record_additionPosition]=ADD_INT(aa,bb);
        }
        for(int i=0;i<count_operation-1;i++){
            split_position[i]=split_position[i+1];
        }
        for(int i=1;i<count_data-1;i++){
            split_data[i]=split_data[i+1];
        }

        count_operation--;
        count_data--;
        addition_exist=false;
        record_additionPosition = 0;
        for(int i=0;i<count_operation;i++){
            if(a[split_position[i]]=='+' || a[split_position[i]]=='-'){
                addition_exist = true;
                record_additionPosition = i;
                break;
            }
        }
    }

    return split_data[0];
}

string kill_all_parentheses(string a){
    int a_len = a.length();
    bool parentheses_exist = false;
    string transformation = "";
    int leftParentheses_position = 0;
    int rightParentheses_position = 0;
    bool contain_formula = false;
    for(int i =0;i<a_len;i++){
        if(a[i]=='('){
            leftParentheses_position = i;
        }else if(a[i]==')'){
            rightParentheses_position = i;
            parentheses_exist = true;
            break;
        }
    }
    for(int i=leftParentheses_position+1;i<rightParentheses_position;i++){
        if(a[leftParentheses_position+1]=='-'){
            i++;
        }
        if(a[i]=='-' && a[i-1]=='e'){
            i++;
        }
        if(a[i]=='+' || a[i]=='-' || a[i]=='*'){
            contain_formula = true;
        }
    }
    while(parentheses_exist==true){
        if(contain_formula==true){
            transformation = a.substr(leftParentheses_position+1,rightParentheses_position-leftParentheses_position-1);
            transformation = calculate_additionAndmultiplication(transformation);
        }else{
            transformation = a.substr(leftParentheses_position+1,rightParentheses_position-leftParentheses_position-1);
        }
        if(leftParentheses_position>3 && a[leftParentheses_position-4]=='s' && a[leftParentheses_position-3]=='q' 
           && a[leftParentheses_position-2]=='r'&& a[leftParentheses_position-1]=='t'){
            a.erase(leftParentheses_position-4,rightParentheses_position-leftParentheses_position+5);
            transformation = sqrt(transformation);
            a.insert(leftParentheses_position-4,transformation);
        }else if(leftParentheses_position>2 && a[leftParentheses_position-3]=='a' 
           && a[leftParentheses_position-2]=='b'&& a[leftParentheses_position-1]=='s'){
            a.erase(leftParentheses_position-3,rightParentheses_position-leftParentheses_position+4);
            transformation = abs(transformation);
            a.insert(leftParentheses_position-3,transformation);
       }else{
            a.erase(leftParentheses_position,rightParentheses_position-leftParentheses_position+1);
            if((a[leftParentheses_position-1]=='+')&&(transformation[0]=='-')){
                a.erase(leftParentheses_position-1,1);
                a.insert(leftParentheses_position-1,transformation);
            }else if((a[leftParentheses_position-1]=='-')&&(transformation[0]=='-')){
                a.erase(leftParentheses_position-1,1);
                transformation.erase(0,1);
                a.insert(leftParentheses_position-1,"+");
                a.insert(leftParentheses_position,transformation);
            }else{
                a.insert(leftParentheses_position,transformation);
            }
            
       }

        a_len = a.length();
        parentheses_exist = false;
        transformation = "";
        leftParentheses_position = 0;
        rightParentheses_position = 0;
        contain_formula = false;
        for(int i =0;i<a_len;i++){
            if(a[i]=='('){
                leftParentheses_position = i;
            }else if(a[i]==')'){
                rightParentheses_position = i;
                parentheses_exist = true;
                break;
            }
        }
        for(int i=leftParentheses_position+1;i<rightParentheses_position;i++){
            if(a[leftParentheses_position+1]=='-'){
                i++;
            }
            if(a[i]=='-' && a[i-1]=='e'){
                i++;
            }
            if(a[i]=='+' || a[i]=='-' || a[i]=='*'){
                contain_formula = true;
            }
        }
        
    }
    return a;
}
