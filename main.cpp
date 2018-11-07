#include <iostream>

using namespace std;



class BigDecimalInt
{


    int sizze;
    int *data;

public:

    BigDecimalInt() {}
    BigDecimalInt(string s)
    {


        if(s[0]=='-')
        {
            sizze=s.length()-1;
            data=new int [sizze];

            for(int i=0; i<sizze; i++)
            {
                data[i]=(s[i+1]-'0')*(-1);
            }
        }
        else
        {
            sizze=s.length();
            data=new int [sizze];

            for(int i=0; i<sizze; i++)
            {
                data[i]=s[i]-'0';
            }
        }

    }
    BigDecimalInt(int decInt) {}




    friend BigDecimalInt operator+  (BigDecimalInt n1,BigDecimalInt n2) ;
    friend BigDecimalInt operator-  (BigDecimalInt n1,BigDecimalInt n2) ;
    friend ostream& operator<< (ostream& out, BigDecimalInt n3);
    friend void sumTheTwoNumber(BigDecimalInt n1,BigDecimalInt n2);
    friend void subtractTheTwoNumber(BigDecimalInt n1,BigDecimalInt n2);

};

void sumTheTwoNumber(BigDecimalInt n1,BigDecimalInt n2)
{


    for(int i=0 ; i < n1.sizze ; i++)
    {
        if(i==n1.sizze-1)
        {
            break;
        }

        if( (n1.data[n1.sizze-1-i]+n2.data[n2.sizze-1-i]) > 9 || (n1.data[n1.sizze-1-i]+n2.data[n2.sizze-1-i]) < -9)
        {
            n1.data[n1.sizze-2-i] +=  ((n1.data[n1.sizze-1-i] + n2.data[n2.sizze-1-i]) / (10) );

            n1.data[n1.sizze-1-i] = ( (n1.data[n1.sizze-1-i]+n2.data[n2.sizze-1-i])  % (10) );

            n2.data[n2.sizze-1-i] = 0;
        }
    }
}


void subtractTheTwoNumber(BigDecimalInt n1,BigDecimalInt n2)
{
    if(n1.data[0] >0 && n2.data[0]<0)
    {
        for(int i=0; i<n1.sizze; i++)
        {
            n2.data[i] *= -1;
        }
        sumTheTwoNumber(n1,n2);

        BigDecimalInt num6;
        num6 = n1 + n2;
        cout << "number1 - number2 = " << num6 << endl;

        exit(0);

    }

    if(n1.data[0] <0 && n2.data[0]>0)
    {
        for(int i=0; i<n1.sizze; i++)
        {
            n2.data[i] *= -1;
        }
        sumTheTwoNumber(n1,n2);

        BigDecimalInt num6;
        num6 = n1 + n2;
        cout << "number1 - number2 = " << num6 << endl;

        exit(0);

    }


    for(int i=0; i<n1.sizze; i++)
    {

        if( (n1.data[n1.sizze-1-i]-n2.data[n2.sizze-1-i]) < 0)
        {
            for ( int j=n1.sizze-2-i ; j>=0 ; j--)
            {
                if ( n1.data[j] > 0 )
                {


                    n1.data[j]--;
                    for ( int k=j+1 ; k<n1.sizze-1-i ; k++ )
                    {
                        n1.data[k] += 9;

                    }
                    n1.data[n1.sizze-1-i] += 10;

                    break;
                }
            }
        }

    }


}



BigDecimalInt operator+  (BigDecimalInt n1,BigDecimalInt n2)
{

    BigDecimalInt result(n1);
    for(int i=0; i<n1.sizze; i++)
    {
        result.data[n1.sizze-1-i] = n1.data[n1.sizze-1-i] + n2.data[n2.sizze-1-i] ;
    }

    if(result.data[0]<=0)
    {

        for(int i=0; i<result.sizze; i++)
        {
            if(result.data[i+1] < 0)
                result.data[i+1] *= (-1);
        }
    }

    return result;



}

BigDecimalInt operator-  (BigDecimalInt n1,BigDecimalInt n2)
{


    BigDecimalInt result(n1);

    for(int i=0 ; i< n1.sizze ; i++)
    {
        result.data[i] = n1.data[i] - n2.data[i] ;
    }

    if(result.data[0]<=0)
    {

        for(int i=0; i<result.sizze; i++)
        {
            if(result.data[i+1] < 0)
                result.data[i+1] *= (-1);
        }
    }

    return result;


}



ostream& operator<< (ostream& out, BigDecimalInt n3)
{
    for(int i=0; i<n3.sizze; i++)
    {
        out<<n3.data[i];
    }
    return out;
}




int main()
{

    int sumORsubtract;
    string theFirstNumber,theSecondNumber;
    cout<<"Enter The first number : \n";
    cin>>theFirstNumber;
    cout<<"Enter The second number : \n";
    cin>>theSecondNumber;

    cout<<"you want to : \n1) Sum  \n2) Subtract \n";
    cin>>sumORsubtract;




    if(sumORsubtract==1)
    {

        BigDecimalInt num1(theFirstNumber),num3;
        BigDecimalInt num2(theSecondNumber);

        sumTheTwoNumber(num1,num2);
        num3 = num1 + num2;
        cout << "number1 + number2 = " << num3 << endl;
    }
    if(sumORsubtract==2)
    {

        BigDecimalInt num1(theFirstNumber),num3;
        BigDecimalInt num2(theSecondNumber);


        subtractTheTwoNumber(num1,num2);
        num3 = num1 - num2;
        cout << "number1 - number2 = " << num3 << endl;
    }
}
