#include "mouse.h"
#include <QDebug>

Mouse::Mouse(QObject *parent)
    : QObject{parent}
{

}

double Mouse::x() const
{
    return m_x;
}

double Mouse::y() const
{
    return m_y;
}

int Mouse::score() const
{
    return m_score;
}

bool Mouse::state() const
{
    return m_state;
}

int Mouse::width() const
{
    return m_width;
}

int Mouse::height() const
{
    return m_height;
}

void Mouse::changePosition()
{
    if (m_state)
    {
        m_score++;

        m_x = rand() % (m_width - 100);
        m_y = rand() % (m_height - 100);

        emit scoreChanged();
        emit positionChanged();
    }
}

void Mouse::move()
{
    srand(time(0));

    int step_x = rand() % 10 - 5;
    int step_y = rand() % 10 - 5;

    if (step_x == 0 && step_x == 0)
    {
        step_x = rand() % 10 - 5;
        step_y = rand() % 10 - 5;
    }

    if ((m_x + step_x >= 0) && (m_x + step_x <= m_width - 100) &&
            (m_y + step_y >= 0) && (m_y + step_y <= m_height - 100))
    {
        m_x += step_x;
        m_y += step_y;

        emit positionChanged();
    }
}

void Mouse::setState(bool state)
{
    m_state = state;
}

void Mouse::windowSize(int width, int height)
{
    m_width = width;
    m_height = height;
}


