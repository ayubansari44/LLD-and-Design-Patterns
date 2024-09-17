#ifndef COINSNOTES_H
#define COINSNOTES_H

class CoinsNotes {
public:
    enum Currency {
        ONE = 1,
        TWO = 2,
        FIVE = 5,
        TEN = 10,
        TWENTY = 20,
        FIFTY = 50,
        HUNDRED = 100,
        FIVE_HUNDRED = 500
    };

private:
    double value;

public:
    CoinsNotes(Currency currency);

    double getValue() const;
};

#endif // COINSNOTES_H
