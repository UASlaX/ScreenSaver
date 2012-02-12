#ifndef SETUP_DIALOG_HPP
#define SETUP_DIALOG_HPP

#include <QtGui/QDialog>
#include "ui_setup_dialog.h"

class SetupDialog
    :   public QDialog
    ,   public Ui::SetupDialogUi
{
public:

    SetupDialog( QWidget * _parent = NULL );

};

#endif // SETUP_DIALOG_HPP
