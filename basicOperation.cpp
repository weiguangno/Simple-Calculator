#include<iostream>
#include<cstring>
#include<cstdlib>
#include"interface.hpp"
using namespace std;

string change_form_tofloat(string a){
    int a_len = a.length();
    int a_point_position = 0;
    int a_e_position = 0;
    bool negative_right = false;
    
    if(a[0]=='-'){
        negative_right = true;
        a.erase(0,1);
    }
    
    for (int i=0; i<a_len; i++){
        if(a[i]=='.'){
            a_point_position = i;
        }
        if (a[i] == 'e'){
            a_e_position = i;
            break;
        }
    }

    if(a_point_position == 0){
        a.insert(a_e_position,".0");
    }

    if(a_e_position==0){
        return a;
    }

    a_len = a.length();
    for (int i=0; i<a_len; i++){
        if(a[i]=='.'){
            a_point_position = i;
        }
        if (a[i] == 'e'){
            a_e_position = i;
            break;
        }
    }

    int fronter_number_count = a_point_position;
    int middle_number_count = a_e_position - a_point_position -1;
    int difference_between_eToEnd = a_len - a_e_position -1 ;
    int later_number = abs(atoi(a.substr(a_e_position+1,difference_between_eToEnd).data()));
    int result_len = a_len + later_number;
    string result[result_len];

    if (a[a_e_position+1]!='-'){
        for(int i=0; i<a_point_position;i++){
            result[i]=a[i];
        }
        if(middle_number_count <= later_number){
            for(int j=a_point_position;j<a_e_position-1;j++ ){
                result[j]=a[j+1];
            }
            for(int j=a_e_position;j<a_point_position+later_number+1;j++){
                result[j]='0';
            }
            result[a_point_position+later_number+1]='.';
            result[a_point_position+later_number+2]='0';
        }else{
            for(int j=a_point_position;j<a_point_position+later_number;j++){
                result[j]=a[j+1];
            }
            result[a_point_position+later_number]='.';
            for(int j = a_point_position+later_number+1;j<a_e_position;j++){
                result[j]=a[j];
            }
        }
    }else{
        if(a_point_position<=later_number){
            result[0]='0';
            result[1]='.';
            for(int i=2;i<1+later_number;i++){
                result[i]='0';
            }
            for(int i=1+later_number;i>1+later_number-a_point_position;i--){
                result[i]=a[i-2-later_number+a_point_position];
            }
            for(int i=2+later_number;i<2+later_number+middle_number_count;i++){
                result[i]=a[i-1-later_number+a_point_position];
            }
        }else{
            for(int i=0;i<a_point_position-later_number;i++){
                result[i]=a[i];
            }
            result[a_point_position-later_number]='.';
            for(int i=a_point_position-later_number+1;i<a_point_position+1;i++){
                result[i]=a[i-1];
            }
            for(int i=a_point_position+1;i<a_e_position;i++){
                result[i]=a[i];
            }
        }
    }
    
    string final_result="";
    for(int i=0;i<result_len;i++){
        final_result += result[i];
    }
    if(negative_right){
        final_result.insert(0,"-");
    }
    return final_result;
}

int compare(string str1,string str2) {//比较字符串型的“数字”大小，相等返回0，大于返回1，小于返回-1
    if (str1.length() > str2.length()) return 1; //长度长的整数大于长度小的整数
    else if (str1.length() < str2.length()) return -1;
    else    return str1.compare(str2); //若长度相等，则头到尾按位比较
}

int compare_leftToright_value(string str1,string str2){
    bool point_exist_str1 = judge_point_Exist(str1);
    bool point_exist_str2 = judge_point_Exist(str2);
    int str1_len = str1.length();
    int str2_len = str2.length();
    int point_position_str1=0;
    int point_position_str2=0;
    string integer_part_str1="";
    string integer_part_str2="";
    string fraction_part_str1="";
    string fraction_part_str2="";
    if(point_exist_str1==false){
        str1=str1+".00";
        str1_len=str1.length();   
    }
    if(point_exist_str2==false){
        str2=str2+".00";
        str2_len=str2.length();   
    }
    int difference = 0;
    if(count_numbersAfterPoint(str1)>count_numbersAfterPoint(str2)){
        difference = count_numbersAfterPoint(str1)-count_numbersAfterPoint(str2);
        str2=add_zerAfterPoint(str2,difference);
        str2_len = str2.length();
    }else{
        difference = count_numbersAfterPoint(str2)-count_numbersAfterPoint(str1);
        str1=add_zerAfterPoint(str1,difference);
        str1_len = str1.length();
    }

    for(int i=0;i<str1_len;i++){
        if(str1[i]=='.'){
            point_position_str1=i;
            break;
        }
    }
    integer_part_str1 = str1.substr(0,point_position_str1);
    fraction_part_str1 = str1.substr(point_position_str1+1,str1_len-point_position_str1-1);
    for(int i=0;i<str2_len;i++){
        if(str2[i]=='.'){
            point_position_str2=i;
            break;
        }
    }
    integer_part_str2 = str2.substr(0,point_position_str2);
    fraction_part_str2 = str2.substr(point_position_str2+1,str1_len-point_position_str2-1);
    if(integer_part_str1.length()>integer_part_str2.length()){
        return 1;
    }else if(integer_part_str1.length()==integer_part_str2.length()){
        for(int i=0;i<integer_part_str1.length();i++){
            if(integer_part_str1[i]>integer_part_str2[i]){
                return 1;
            }else if(integer_part_str1[i]<integer_part_str2[i]){
                return -1;
            }
        }
    }else if(integer_part_str1.length()<integer_part_str2.length()){
        return -1;
    }
    for(int i=0;i<fraction_part_str1.length();i++){
        if(fraction_part_str1[i]>fraction_part_str2[i]){
            return 1;
        }else if(fraction_part_str1[i]<fraction_part_str2[i]){
            return -1;
        }
    }
    return 0;
}

string cut_half(string a){
    int point_position = 0;
    int a_len = a.length();
    for(int i=0;i<a.length();i++){
        if(a[i]=='.'){
            point_position = i;
        }
    }
    a.erase(point_position,1);
    a_len = a.length();
    int digit_number = a[0]-'0';
    bool is_odd = false;
    if((digit_number%2)==1){
        digit_number--;
        digit_number = digit_number/2;
        is_odd=true;
    }else{
        digit_number = digit_number/2;
    }
    a.erase(0,1);
    a.insert(0,to_string(digit_number));
    for(int i=1;i<a_len-1;i++){
        if(is_odd==true){
            is_odd=false;
            digit_number = a[i]-'0';
            digit_number+=10;
            if((digit_number%2)==1){
                digit_number--;
                digit_number = digit_number/2;
                is_odd=true;
            }else{
                digit_number = digit_number/2;
            }
        }else{
            digit_number = a[i]-'0';
            if((digit_number%2)==1){
                digit_number--;
                digit_number = digit_number/2;
                is_odd=true;
            }else{
                digit_number = digit_number/2;
            }
        }
        a.erase(i,1);
        a.insert(i,to_string(digit_number));
    }
    if(is_odd==true){
        is_odd=false;
        digit_number = a[a_len-1]-'0';
        digit_number+=10;
        if((digit_number%2)==1){
            digit_number--;
            digit_number = digit_number/2;
            is_odd=true;
            a.erase(a_len-1,1);
            a.insert(a_len-1,to_string(digit_number));
            a=a+"5";
        }else{
            digit_number = digit_number/2;
            a.erase(a_len-1,1);
            a.insert(a_len-1,to_string(digit_number));
        }
    }else{
        digit_number = a[a_len-1]-'0';
        if((digit_number%2)==1){
            digit_number--;
            digit_number = digit_number/2;
            is_odd=true;
            a.erase(a_len-1,1);
            a.insert(a_len-1,to_string(digit_number));
            a=a+"5";
        }else{
            digit_number = digit_number/2;
            a.erase(a_len-1,1);
            a.insert(a_len-1,to_string(digit_number));
        }
    }
    a.insert(point_position,".");
    if(a[0]=='0' && a[1]!='.'){
        a.erase(0,1);
    }
    return a;
}

string ADD_INT(string str1,string str2) {//高精度加法
    int sign = 1; //sign 为符号位
    string str;
    if (str1[0] == '-') //如果其中一个是负数，那么可以转化成高精度减法；如果都是负数，那么确定下结果为负数，然后擦除负号后相加
    {
        if (str2[0] == '-') 
        {
            sign = -1;
            str = ADD_INT(str1.erase(0,1),str2.erase(0,1));
        } 
        else 
        {
            str = SUB_INT(str2,str1.erase(0,1));
        }
    } 
    else
    {
        if (str2[0] == '-') 
        {
            str = SUB_INT(str1,str2.erase(0,1));
        }
        else 
        { 
            int L1,L2;
            L1 = str1.length();
            L2 = str2.length();
            if (L1 < L2)              //在长度小的前面加0补齐，使得两数对齐 
            {
                for (int i = 1;i <= L2-L1; i++) str1="0"+str1;
            } 
            else 
            {
                for (int i = 1;i <= L1-L2; i++) str2="0"+str2;
            }
            int int1 = 0,carry = 0; //carry 记录进位
            for (int i = str1.length()-1;i >= 0; i--) 
            {
                int1 = (int(str1[i])-'0'+ int(str2[i])-'0'+carry) % 10;
                carry = (int(str1[i])-'0'+ int(str2[i])-'0'+carry) / 10;
                str = char(int1 + '0') + str;
            }
            if (carry != 0) str = char(carry+'0') + str;
        }
    }
    
    if ((sign==-1)&&(str[0]!='0')) str="-"+str;    //处理符号位
    return str;
}

string SUB_INT(string str1,string str2) {//高精度减法
    int sign=1; //sign 为符号位
    string str;
    int i,j;
    if (str2[0] == '-')    //减一个负数等于加上它的相反数 
    {
        str = ADD_INT(str1,str2.erase(0,1));
    } 
    else 
    {
        if (str1[0] == '-')           //负数减去正数 
        {
            sign = -1;
            str = ADD_INT(str1.erase(0,1),str2);
        }
        else
        {
            int res = compare(str1,str2);
            if (res == 0) return "0";      //两数相等则结果是0 
            if (res < 0)                   //被减数比较小，则符号先确定为负 
            {
                sign = -1;
                string temp = str1;
                str1 = str2;
                str2 = temp;
            }
            int tempint;
            tempint=str1.length()-str2.length();
            for (i=str2.length()-1;i>=0;i--) 
            {
                if (str1[i+tempint]<str2[i])   //需要向前借位的情况 
                {
                    j=1;
                    while (1) 
                    {
                        if (str1[i+tempint-j]=='0')   //被借的位如果是 0 ，那么继续借位，并把当前的 0 变成 9 
                        {
                            str1[i+tempint-j]='9';
                            j++;
                        } 
                        else 
                        {
                            str1[i+tempint-j]=char(int(str1[i+tempint-j])-1);  // 被借的位如果不是 0 ，那么减去 1
                            break;
                        }
                    }
                    str=char(str1[i+tempint]-str2[i]+'0'+10)+str;
                } 
                else 
                {
                    str=char(str1[i+tempint]-str2[i]+'0')+str;
                }
            }
            for (i=tempint-1;i>=0;i--) str=str1[i]+str;
        }
    }
    //去除结果中多余的前导0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str="0";
    if ((sign==-1) && (str[0]!='0')) str ="-"+str;
    return str;
}

string MUL_INT(string str1,string str2) {   //高精度乘法
    int sign = 1;   //sign 为符号位
    string str;
    if (str1[0]=='-') 
    {         //确定结果正负 
        sign *= -1;
        str1 = str1.erase(0,1);
    }
    if (str2[0]=='-') 
    {
        sign *= -1;
        str2 = str2.erase(0,1);
    }
    int L1,L2;
    L1 = str1.length();
    L2 = str2.length();
    for (int i = L2-1;i >= 0;i--) //模拟手工乘法竖式
    { 
        string temps;              //temps存当前str2某一位乘于str1的结果    
        int int_res=0,carry=0,int2=str2[i]-'0';  //carry存进位的数量，int2存str2的某一位 
        if (int2 != 0) 
        {
            for (int j = 1;j <= L2-1-i; j++) temps = "0"+temps;   //这里就是上面所说的加上相应位数的 0 的操作 
            for (int j = L1-1;j >= 0;j--) 
            {
                int_res = (int2 * (int(str1[j]) - '0') + carry) % 10;
                carry = (int2 *(int(str1[j]) - '0') + carry) / 10;
                temps = char(int_res + '0') + temps;
            }
            if (carry != 0) temps = char(carry +'0') + temps;
        }
        str = ADD_INT(str,temps);         //这里就是上面所说的乘法是基于加法的 
    }
    //去除结果中的前导0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str = "0";
    if ((sign==-1) && (str[0]!='0')) str = "-" + str;
    return str;
}

int count_numbersAfterPoint(string a){
    int a_len = a.length();
    int point_position = 0;
    for(int i=0;i<a_len;i++){
        if(a[i]=='.'){
            point_position=i;
            break;
        }
    }
    int number = a_len - point_position - 1;
    return number;
}

string earse_point(string a){
    int a_len = a.length();
    int point_position = a.find('.');
    a.erase(point_position,1);
    return a;
}

string insert_point_mul(string a,int number){
    int a_len = a.length();
    int point_position = a_len - number;
    a.insert(point_position,".");
    return a;
}

string add_zerAfterPoint(string a,int difference){
    for(int i=0;i<difference;i++){
        a = a + "0";
    }
    return a;
}

string ADD_FLOAT(string a,string b){
    int count_a = count_numbersAfterPoint(a);
    int count_b = count_numbersAfterPoint(b);
    int difference = 0;
    int max = count_a;
    if(count_a>count_b){
        difference = count_a - count_b;
        b = add_zerAfterPoint(b, difference);
    }else if(count_a<count_b){
        difference = count_b - count_a;
        a = add_zerAfterPoint(a, difference);
        max = count_b;
    }
    string aa = earse_point(a);
    string bb = earse_point(b);
    string cc = ADD_INT(aa,bb);
    int cc_len = cc.length();
    int point_position = cc_len - max;
    if(point_position<=0){
        if(cc[0]=='-'){
            cc.erase(0,1);
            cc.insert(0,"-0.");        
            int count = 1;
            point_position--;
            for(int i=point_position;i<0;i++){
                cc.insert(2+count,"0");
                count++;
            }
        }else{
            cc.insert(0,"0.");        
            int count = 1;
            for(int i=point_position;i<0;i++){
                cc.insert(1+count,"0");
                count++;
            }
        }        
    }else{
        cc.insert(point_position,".");
    }
    return cc;
}

string SUB_FLOAT(string a,string b){
    int count_a = count_numbersAfterPoint(a);
    int count_b = count_numbersAfterPoint(b);
    int difference = 0;
    int max = count_a;
    if(count_a>count_b){
        difference = count_a - count_b;
        b = add_zerAfterPoint(b, difference);
    }else if(count_a<count_b){
        difference = count_b - count_a;
        a = add_zerAfterPoint(a, difference);
        max = count_b;
    }
    string aa = earse_point(a);
    string bb = earse_point(b);
    string cc = SUB_INT(aa,bb);
    int cc_len = cc.length();
    int point_position = cc_len - max;
    cc.insert(point_position,".");
    return cc;
}

string MUL_FlOAT(string a,string b){
    int count_a = count_numbersAfterPoint(a);
    int count_b = count_numbersAfterPoint(b);
    string aa = earse_point(a);
    string bb = earse_point(b);
    string mul = MUL_INT(aa,bb);
    int number = count_a + count_b;
    int point_position = mul.length() - number;
    if(point_position<=0){
        if(mul[0]=='-'){
            mul.erase(0,1);
            mul.insert(0,"-0.");        
            int count = 1;
            point_position--;
            for(int i=point_position;i<0;i++){
                mul.insert(2+count,"0");
                count++;
            }
        }else{
            mul.insert(0,"0.");        
            int count = 1;
            for(int i=point_position;i<0;i++){
                mul.insert(1+count,"0");
                count++;
            }
        }        
    }else{
        mul = insert_point_mul(mul,number);
    }
    return mul;
}

