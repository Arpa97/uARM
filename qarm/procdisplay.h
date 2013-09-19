/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
 * uARM
 *
 * Copyright (C) 2013 Marco Melletti
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef PROCDISPLAY_H
#define PROCDISPLAY_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <sstream>
#include <iomanip>
#include "QLine.h"
#include "armProc/const.h"
#include "guiConst.h"

class monoLabel;

class procDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit procDisplay(QWidget *parent = 0);
        
public slots:
    void updateVals(Word *cpu, Word *cp15, Word *pipeline, QString ass);
    void reset();

private:
    QVBoxLayout *mainLayout;
    QGridLayout *pipeL, *cpuL, *cp15L;
    monoLabel **pipeline;
    monoLabel ***cpuReg, ***cp15Reg;

    QString convertHex(Word val);
};

class monoLabel : public QLabel{
public:
    monoLabel(QWidget *parent = 0, Qt::WindowFlags f = 0) : QLabel(parent, f){
        setFont(getMonospaceFont());
    }

    monoLabel(QString text, QWidget *parent = 0, Qt::WindowFlags f = 0) : QLabel(parent, f){
        monoLabel();
        setText(text);
    }

    static const QFont getMonospaceFont()
    {
        QFont monospaceFont("monospace");
        monospaceFont.setStyleHint(QFont::TypeWriter);
        monospaceFont.setPointSize(10);
        return monospaceFont;
    }
};

#endif // PROCDISPLAY_H
