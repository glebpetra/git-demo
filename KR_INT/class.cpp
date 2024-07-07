#include <QString>
#include <QTextStream>
#include <QDebug>
#include <string>
#include <QMessageBox>
using namespace std;

template <typename T>
struct Node
{
    T info;
    Node* next;
};

template <class T>
class My_List
{
protected:
    Node<T>* head;

public:
    void delete_last();
    bool is_empty();
    void push_tail(T);
    Node<T>* find_value_by_info(T);
    void show_list(QString& str);
    void sort();
    bool is_elem(T);
    My_List();
    My_List(const My_List&);
    virtual ~My_List();

};


template <typename T>
My_List<T>::~My_List()
{
    if (!is_empty())
    {
        Node<T>* temp = head->next;
        while (temp != nullptr)
        {
            Node<T>* res = temp->next;
            delete temp;
            temp = res;
        }
    }
    delete head;
}

template <typename T>
My_List<T>::My_List()
{
    head = NULL;
}

template <typename T>
My_List<T>::My_List(const My_List& spis)
{
    if (spis.head == NULL)
        this->head = NULL;
    else
    {
        this->head = new Node<T>;
        Node<T>* temp = spis.head;
        Node<T>* copy = this->head;
        while (temp->next != nullptr)
        {
            copy->info = temp->info;
            copy->next = new Node<T>;
            copy = copy->next;
            temp = temp->next;
        }
        copy->info = temp->info;
        copy->next = nullptr;
    }
}

template <typename T>
bool My_List<T>::is_empty()
{
    if (head == NULL)
        return 1;
    return 0;
}


template <typename T>
void My_List<T>::push_tail(T value)
{
    if (is_empty())
    {
        Node<T>* temp = new Node<T>;
        temp->next = nullptr;
        temp->info = value;
        head = temp;
    }
    else
    {
        Node<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node<T>;
        temp->next->next = nullptr;
        temp->next->info = value;
    }
}

template <typename T>
Node<T>* My_List<T>::find_value_by_info(T value)
{
    Node<T>* temp = head;
    while (temp->next != nullptr)
    {
        if (temp->info == value)
            return temp;
        temp = temp->next;
    }
}

template <typename T>
bool My_List<T>::is_elem(T value)
{
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        if (temp->info == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

template <typename T>
void My_List<T>::show_list(QString& str)
{
    if (is_empty())
    {
        str = "The output is empty";
    }
    else
    {
        str = "{";
        Node<T>* temp = head;
        if constexpr (std::is_same_v<T, char*>)
            str += QString::fromStdString(temp->info);
        else
            str += QString::fromStdString(std::to_string(temp->info));
        while (temp->next != nullptr)
        {
            str += ", ";
            temp = temp->next;
            if constexpr (std::is_same_v<T, char*>)
                str += QString::fromStdString(temp->info);
            else
                str += QString::fromStdString(std::to_string(temp->info));
        }
        str += "}";
    }
}


template <typename T>
void My_List<T>::delete_last()
{
    if (!is_empty())
    {
        Node<T>* temp = head;
        if (temp->next == nullptr)
        {
            delete temp;
            head = nullptr;
        }
        else
        {
            while (temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

template <typename T>
void My_List<T>::sort()
{
    if (!is_empty())
    {
        Node<T>* number = head;
        while (number != nullptr)
        {
            Node<T>* temp = head;
            while (temp->next->next != nullptr)
            {
                if (temp->next > temp)
                {
                    swap(temp->info, temp->next->info);
                }
                temp = temp->next;
            }
            number = number->next;
        }
    }
}




template <typename T>
class My_set : public My_List<T> {
public:

    friend QTextStream& operator>>(QTextStream& in, My_set<T>& set)
    {
        T temp;
        in >> temp;
        if (!set.is_elem(temp))
        {
            set.push_tail(temp);
            return in;
        }
        else
            QMessageBox::critical(nullptr, "Error", "This is not a set!");
    }

    friend QTextStream& operator<<(QTextStream& out, My_set<T>& set)
    {
        out << "{";
        Node<T>* temp = set.head;
        while (temp->next != nullptr)
        {
            out << temp->info << ", ";
            temp = temp->next;
        }
        out << temp->info;
        out << "}";
        return out;
    }

    My_set<T> operator+(My_set<T>& other)
    {
        My_set<T> res;
        Node<T>* temp = this->head;
        while (temp != nullptr)
        {
            res.push_tail(temp->info);
            temp = temp->next;
        }
        temp = other.head;
        while (temp != nullptr)
        {
            if (!(this->is_elem(temp->info)))
            {
                res.push_tail(temp->info);
            }
            temp = temp->next;
        }
        return res;
    }


    My_set<T> operator*(My_set<T>& other)
    {
        My_set<T> res;
        Node<T>* temp = this->head;
        while (temp != nullptr)
        {
            if (other.is_elem(temp->info))
                res.push_tail(temp->info);
            temp = temp->next;
        }
        return res;
    }

};
