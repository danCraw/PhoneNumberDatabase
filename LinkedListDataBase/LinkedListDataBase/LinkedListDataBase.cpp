#include <iostream>
using namespace std;
int quantityElements = 0;
// Два варианта телефонных абонентов: квартира и учреждение.
struct phone
{
    phone* Next;   // Указатель на следующую структуру в списке.
    char model[60];
    int price;
    int yearOfIssue;
};
// Указатель начала списка - базы данных:
phone* DataBase = NULL;
// Вывод информации о телефонном абоненте:
void OutSubscriberInfo(phone scb)
{
    setlocale(LC_ALL, "Russian");
    if (scb.model)
    {
        cout << scb.model << " |";
        for (int i = 0; i < scb; i++)
            cout << ' ' << scb.Office.Phone[i];
    }
    else cout << scb.Home.Surname << ' ' << scb.Home.Name << " | "
        << scb.Home.Phone;
    cout << " | " << scb.price << endl
        << "ВРЕМЯ РАЗГОВОРА: " << scb.Time << " сек." << endl;
}
/* Поиск в списке абонента с заданным порядковым номером num в списке
(нумеруем, начиная с 0):   */
phone* FoundSubscriberNum(int num)
{
    setlocale(LC_ALL, "Russian");

    phone* p = DataBase;
    while (p != NULL && num--)   // Пока не конец списка и не найден номер,
        p = p->Next;            // продвигаем указатель вдоль списка.
    return p;   // Возвращаем указатель на найденный элемент или NULL,
}              /* если элемент не найден.
   Добавить нового абонента в список за номером num:   */
void AddSubscriber(int num, char cs)
{
    setlocale(LC_ALL, "Russian");

    phone* q = new phone;// Создали новую структуру.
    *q = InpSubscriberInfo(cs);    // Заполнили ее информацией.
    if (DataBase == NULL) num = 0;   // Если список пустой - добавим в начало.
    if (num)
    {
        phone* p = DataBase;      // Ищем указатель
        while (p->Next != NULL && --num) // на предыдущую структуру.
            p = p->Next;
        q->Next = p->Next; p->Next = q;// Вставляем новую структуру после *p
    }
    else { q->Next = DataBase; DataBase = q; } // Добавим в начало списка.
}
// Удалить абонента с номером num из списка:
void DeleteSubscriber(int num)
{
    setlocale(LC_ALL, "Russian");

    phone* q;
    if (DataBase == NULL) return;
    if (num)
    {
        phone* p = DataBase;// Ищем указатель на предыдущую структуру.
        while (p->Next != NULL) 
            p = p->Next;
        if ((q = p->Next) != NULL) {
            p->Next = q->Next; 
            delete q; 
        }
    }                           // Удаляем начальный элемент:
    else { q = DataBase; DataBase = q->Next; delete q; }
}

void action(string nextAction, ) {
    bool actionUnderstanding = false;
    if (nextAction._Equal("remove")) {
        actionUnderstanding = true;
        if (quantityElements == 0) {
            cout << " \n База данных пуста, добавьте элемент и повторите попытку \n";
        }
        else
        {
            phone* q;
            string name;
            cout << " \n Введите модель, которцю вы хотели бы удалить: \t";
            cin >> name;
            for (int i = 0; i < quantityElements; i++) {
                if (name._Equal(arr[i].model))
                    *(arr + i) = *(arr + (i + 1));
                quantityElements--;
                cout << " \n Объект удален\n";
            }
        }
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    int quantityElements = 2;
    string name;
    string nextAction;
    phone* arr = new phone[quantityElements];
    cout << "Для изменения базы данных введите :" << "\"" << "add" << "\" или ""\"" << "renove" << "\" " << endl;
    cout << "Чтобы вывести базу данных, введите " << "\"" << "show" << "\"" << endl;
    cout << "Для выхода введите " << "\"" << "exit" << "\"" << endl;

    while (!nextAction._Equal("EXIT")) {
        cout << "\n Ваше дейкстие: \t";
        cin >> nextAction;
        action(nextAction, arr);
    }
    getchar;
}