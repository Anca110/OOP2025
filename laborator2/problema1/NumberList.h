//contine doar declararea clasei( sau functii)
class NumberList 
{
private:
    int numbers[10];// vector cu elementele din lista
    int count;//cate nr se adauga in lista

public:
    void Init();// initializez count = 0
    bool Add(int x);//Adauga un nr în listã, maxim 10
    void Sort();//Sorteazã lista
    void Print();
};
