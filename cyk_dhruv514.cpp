#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#define MAX 100
int temp;
string grammar_matrix[MAX][MAX];
string production_rules[MAX];
int No_of_Rules;
void Parse_grammar(string a)
{
    int i;
    temp=0;
    while(a.length())
    {
        i=a.find("|");
        if(i>a.length())
        {
            production_rules[temp++] = a;
            a="";
        }
        else
        {
            production_rules[temp++] = a.substr(0,i);
            a=a.substr(i+1,a.length());
          }}}
string Concatenation(string a,string b)
{
    int i;
    string r=a;
    for(i=0;i<b.length();i++)
        if(r.find(b[i]) > r.length())
            r+=b[i];
    return (r);
}

string search_prod(string p) //returns a Concatenationenated string of variables which can produce string p
{
    int j,k;
    string r="";
    for(j=0;j<No_of_Rules;j++)
    {
        k=1;
        while(grammar_matrix[j][k] != "")
        {
            if(grammar_matrix[j][k] == p)
            {
                r=Concatenation(r,grammar_matrix[j][0]);
            }
            k++;
        }
    }
    return r;
}
string Probable_trials(string st1,string st2)
    {
      int i,j;
    string pri=st1,re="";
    for(int i=0;i<st1.length();i++)
        for(j=0;j<st2.length();j++)
        {
            pri="";
            pri=pri+st1[i]+st2[j];
            re=re+search_prod(pri);
        }
    return re;
}
int main()
{
    int i,j,k;
    int arrow_loc;
    string a,str,r,pr,start;
    string final_matrix[MAX][MAX],st;
    cout<<"\nSTART VARIABLE (S) : ";
    cin >> start;
    cout<<"\nNO. OF RULES : ";
    cin >> No_of_Rules;
    for(i=0;i<No_of_Rules;i++)
    {
        cout<<"\nEnter Rule "<<i+1<<" : ";
        cin >> a;
        arrow_loc=a.find("->");
        grammar_matrix[i][0] = a.substr(0,arrow_loc);
        a = a.substr(arrow_loc+2, a.length());
        Parse_grammar(a);
        for(j=0;j<temp;j++)
            grammar_matrix[i][j+1]=production_rules[j];
    }
    cout<<"\nTEST STRING (in small letters eg. abc) : ";
    cin >> str;
    cout<<"\n------------------------";
    for(i=0;i<str.length();i++)
        {
          r="";
        st = "";
        st+=str[i];
        for(j=0;j<No_of_Rules;j++)
        {
            k=1;
            while(grammar_matrix[j][k] != "")
            {
                if(grammar_matrix[j][k] == st)
                    r=Concatenation(r,grammar_matrix[j][0]);
                k++;
            }}
        final_matrix[i][i]=r;
    }
    int l;
    for(int k=1;k<str.length();k++)
        for(j=k;j<str.length();j++)
        {
            r="";
            for(l=j-k;l<j;l++)
            {
                pr = Probable_trials(final_matrix[j-k][l],final_matrix[l+1][j]);
                r = Concatenation(r,pr);
            }
            final_matrix[j-k][j] = r;
        }

    for(i=0;i<str.length();i++)
    {
        k=0;
        l=str.length()-i-1;
        for(j=l;j<str.length();j++)
            cout<<setw(5)<<final_matrix[k++][j]<<" ";
        cout<<endl;
    }
    cout<<"\n------------------------\n";
    for(i=0;i<start.length();i++)
    {
    int t2=final_matrix[0][str.length()-1].length();
    int t1=final_matrix[0][str.length()-1].find(start[i]);
        if( t1<=t2 )
        {
            cout<<"Okay ! Can be produced...\n";
            return 0;
        }
      }
    cout<<"Can't be Generated...\n";
    return 0;
}

//SAMPLE :
/*
START VARIABLE (S) : S

NO. OF RULES : 4

Enter Rule 1 : S->AB|BC

Enter Rule 2 : A->BA|a

Enter Rule 3 : B->CC|b

Enter Rule 4 : C->AB|a

TEST STRING (in small letters eg. abc) : baaba
*/
