#include "CoinsNotes.h"

CoinsNotes::CoinsNotes(Currency currency) {
    this->value = static_cast<double>(currency);
}

double CoinsNotes::getValue() const {
    return value;
}
