#include <iostream>
using namespace std;
void func ()
{
    cout<<"hello world"<<endl;
}
void dosth(void(*myfunc)())
{
    (*myfunc)();

}
int main()
{
    void(*funcptr)()=func;
    func();
    dosth(funcptr);
    return 0;


}