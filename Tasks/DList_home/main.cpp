using namespace std;

struct DNode
{
    int d;
    DNode *p, *n;
};

struct DList
{
    DNode *h, *t; // указатели на первый и последний элементы
    DList(); // пустой список
    DList(const DList &); // конструктор копирования
    DList &operator = (const DList &); // операция присваивания
    ~DList(); // удалить все элементы
    void add_first(int x); // добавить в начало
    void del_first(); // удалить из начала
    void add_last(int x); // добавить в конец
    void del_last(); // удалить последний
    void add_i(int i, int x); // добавить в указанную позицию
    void del_i(int i); // удалить i-й
    void del_ptr(DNode *p); // удалить тот узел, на который указывает p
    void splice(DNode *p, DList &L); // вклеить элементы списка L
                                    // сразу после элемента, на который указывает p. После этого
                                    // список L остается пустым
    DNode *find(int d); // указатель на узел с данными d
    void swap(); // меняет местами первые два элемента.
    void reverse(); // изменить порядок элементов
                    // на обратный; можно менять только указатели
};


void DList::swap()
{
    DNode *a, *b, *c;
    if(h==t) // в списке меньше двух узлов
        return;
    a = h; b = h->n; c = h->n->n; // вспомогательные указатели
    h = b;
    a->p = b; a->n = c; // бывший первый узел станет вторым
    b->p = nullptr; b->n = a; // бывший второй узел станет первым
    if(c!=nullptr)
        c->p = a; // если было больше двух узлов
    else
        t = a;    // если было ровно два узла
}


void DList::add_first(int x)
{
    DNode *a, *b;
    if (h == nullptr)
    {
        h->n = nullptr;
        h->p = nullptr;
        h->d = x;
        t = h;
        return;
    }
    b = h; h = a;
    b->p = h; a->n = b; a->p = nullptr; a->d = x;
}


void DList::del_first()
{
    DNode *a;
    if (h == nullptr) return;
    a = h;
    h = h->n; h->p = nullptr;
    delete a;
}


void DList::add_last(int x)
{
    DNode *a, *b;
    if (t == nullptr)
    {
        t->n = nullptr;
        t->p = nullptr;
        t->d = x;
        h = t;
        return;
    }
    b = t; b->n = a; a->d = x; t = a;
}


void DList::del_last()
{
    DNode *a;
    if (t == nullptr) return;
    a = t; t = t->p; t->n = nullptr;
    delete a;
}


void DList::add_i(int i, int x)
{

}