//queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H__
#define QUEUETP_H__

template <class Item>
class QueueTP
{
    private:
        enum {Q_SIZE = 10};
        class Node
        {
            public:
                Item item;
                Node *next;
                Node(const Item &i) : item(i), next(0) {}
        };
        Node *front;
        Node *rear;
        int items;
        const int qsize;
        QueueTP(const QueueTP &q) : qsize(0) {}
        QueueTP & operator=(const QueueTP &q) { return *this; }
    public:
        QueueTP(int qs = Q_SIZE);
        ~QueueTP();
        bool isempty() const { return items == 0; }
        bool isfull() const { return items == qsize; }
        int queuecount() const { return items; }
        bool enqueue(const Item &item);
        bool dequeue(Item &item);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = 0;
    items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node *add = new Node(item);
    items++;
    if (front == 0)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
    if (front == 0)
        return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = 0;
    return true;
}

#endif

