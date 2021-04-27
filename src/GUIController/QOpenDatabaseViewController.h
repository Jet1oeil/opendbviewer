/*
 * QOpenDatabaseViewController.h
 *
 *  Created on: 10 juin 2016
 *      Author: echopin
 */

#ifndef SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_
#define SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_

#include <QObject>
#include <QString>

#include "Database/DatabaseController.h"

class QWindowMainController;
class QDatabaseConnectionViewController;
class QOpenDatabaseView;
class QWindowMain;

class QOpenDatabaseViewController : public QObject
{
	Q_OBJECT
public:
	QOpenDatabaseViewController(QWindowMain* pMainWindow, QWindowMainController* pMainWindowController);
	virtual ~QOpenDatabaseViewController();

	QString getFileUrl() const;
	DatabaseModel selectDatabase(DatabaseModel::DatabaseType type);
	void loadDatabase(const DatabaseModel&  databaseModel);
	void openSQLiteFile(const QString& szFileUrl);
	void resetForms();

private:
	void recoverMySQLDatabaseInfo(DatabaseModel * database);
	void recoverPostgreSQLInfo(DatabaseModel * database);

public slots:
	void openFileDialog();
	void closeOpenDatabaseDialog();

	void prepareConnection(DatabaseModel::DatabaseType type);
	void loadHistoryDatabase(const DatabaseModel& databaseModel);

	void openConnectionMenu(int index);

private:
	QWindowMain* m_pMainWindow;
	QWindowMainController* m_pMainWindowController;
	QOpenDatabaseView* m_pOpenDatabaseView;
};

#endif /* SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_ */
