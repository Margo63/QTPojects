#include "changes.h"

Changes::Changes(QObject *parent):
    QObject(parent),isVisible(true)
{

}

void Changes::changeVisibility(){
    isVisible=!isVisible;
    emit visibilityChanged();
}

bool Changes::getVisibility() const{
    return isVisible;
}
