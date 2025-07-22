#include <mutex>
#include <thread>
#include <iostream>

using namespace std;
mutex trava;

int contador_com_mtx = 0;
int contador_sem_mtx = 0;

void run_mtx(){
    
    for(int i = 0; i < 100000; i++){
        trava.lock();
        contador_com_mtx++;
        trava.unlock();
    }
    
}       

void run(){
    for(int i = 0; i < 100000; i++){
        contador_sem_mtx++;
    }
}
int main(){
    
    thread t1(run_mtx);
    thread t2(run_mtx);

    thread t3(run);
    thread t4(run);

    t1.join();
    t2.join();
    
    t3.join();
    t4.join();

    cout << "Valor contador com mutex : " << contador_com_mtx << endl;
    cout << "Valor contador sem mutex : " << contador_sem_mtx << endl;
    
    return 0;
}