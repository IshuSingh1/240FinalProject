#ifndef THINGS_H
#define THINGS_H


class Things
{
public:
    Things();
    char getNN();
    void setNN(char);
    void setHP(int);
    int getHP();
protected:
    char nickName;
};

#endif // THINGS_H
