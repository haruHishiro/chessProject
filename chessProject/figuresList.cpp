#include "figuresList.h"
#include <stdio.h>


figuresList::figuresList() {
    figuresList::firstFigure = nullptr;
}

figuresList::~figuresList() {
    figuresList::clear();
}

figure* figuresList::operator[](const unsigned short index) {
    if (figuresList::isEmpty()) return nullptr;
    figure* f = figuresList::firstFigure;
    for (unsigned short i = 0; i < index; i++) {
        f = f->getNextFigure();
        if (!f) return nullptr;
    }
    return f;
}

bool figuresList::isEmpty() {
    return figuresList::firstFigure == nullptr;
}

void figuresList::addFigure(char figureName, bool isWhite, char posX, char posY) {
    switch (figureName) {
    case 'P':
        break;
    case 'N':
        break;
    case 'B':
        break;
    case 'R':
        break;
    case 'Q':
        break;
    case 'K':
        break;
    default:
        break;
    }
}

void figuresList::removeFirst() {
    if (figuresList::isEmpty()) return;
    figure* f = figuresList::firstFigure;
    figuresList::firstFigure = f->getNextFigure();
    delete f;
}

void figuresList::remove(const unsigned short index) {
    if (figuresList::isEmpty()) return;
    figure* f = figuresList::firstFigure;
    for (unsigned short i = 0; i < index - 1; i++) {
        f = f->getNextFigure();
    }
    figure* fToDelete = f->getNextFigure();
    f->setNextFigure(fToDelete->getNextFigure());
    delete fToDelete;
}

void figuresList::clear() {
    while (figuresList::firstFigure){
        figuresList::removeFirst();
    }
}

void figuresList::printFigures() {
    if (figuresList::isEmpty()) {
        printf("No figures\n");
        return;
    }
    figure* f = figuresList::firstFigure;
    do {
        printf("%c", f->getFigureName());
        f = f->getNextFigure();
    } while (f);
}

figure* figuresList::getFirst() {
    return nullptr;
}

figure* figuresList::getLast() {
    return nullptr;
}
