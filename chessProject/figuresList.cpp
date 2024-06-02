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

char figuresList::getFiguresNumber() {
    char counter = 0;
    if (figuresList::isEmpty()) return counter;
    figure* f = figuresList::firstFigure;
    for (;f;) {
        f = f->getNextFigure();
        counter++;
    }
    return counter;
}

figure* figuresList::getFigure(unsigned short index) {
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
    figure* fig = new figure(figureName, isWhite, posX, posY);

    if (figuresList::isEmpty()) {
        figuresList::firstFigure = fig;
        return;
    }

    figure* f = figuresList::getLast();
    f->setNextFigure(fig);
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
    printf("\n");
}

figure* figuresList::getFirst() {
    return figuresList::firstFigure;
}

figure* figuresList::getLast() {
    if (figuresList::isEmpty()) return nullptr;
    figure* f = figuresList::firstFigure;
    while (f->getNextFigure()) {
        f = f->getNextFigure();
    }
    return f;
}
