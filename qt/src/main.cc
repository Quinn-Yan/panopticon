#include <QtCore>
#include <QApplication>
#include <QQmlApplicationEngine>

#include <linearview.hh>
#include <session.hh>

using namespace std;

int main(int argc, char *argv[])
{
	//qmlRegisterType<GraphScenePath>("Panopticon",1,0,"Path");
	//qmlRegisterType<GraphSceneItem>("Panopticon",1,0,"Graph");
	//qmlRegisterType<LinearSceneModel>("Panopticon",1,0,"LinearSceneModel");
	qmlRegisterType<Element>("Panopticon",1,0,"Element");
	qmlRegisterType<Header>("Panopticon",1,0,"Block");
	//qmlRegisterType<GraphScenePen>("Panopticon",1,0,"Pen");
	qmlRegisterType<Session>("Panopticon",1,0,"Session");
	qmlRegisterType<LinearView>("Panopticon",1,0,"LinearView");

	QApplication app(argc, argv);
  QQmlApplicationEngine engine(QUrl("qrc:/Window.qml"));

	QListIterator<QObject*> iter(engine.rootObjects());
	while(iter.hasNext())
	{
		QQuickWindow *window = qobject_cast<QQuickWindow *>(iter.next());

		if(window)
	  	window->show();
	}

	//win.show();
	/*QScrollArea scroll;
	QDeclarativeView view(QUrl("qrc:/Procedure.qml"));

	scroll.setWidget(&view);
	scroll.setWidgetResizable(true);
	scroll.show();*/
	return app.exec();
}
