#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H
#include "mainwindow.h"
#include "CodeEditor.h"
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(QPlainTextEdit* editor);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPlainTextEdit* codeEditor;
};
#endif // LINENUMBERAREA_H
