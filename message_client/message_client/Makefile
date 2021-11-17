PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

MESSAGE_COMMON_ROOT = $(PROJECT_ROOT)../../message_common/

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_DBUS_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtDBus -isystem /usr/include/x86_64-linux-gnu/qt5/QtNetwork -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = message_client1.0.0
DISTDIR = /mnt/hgfs/vm_shared/workspace/message_client/message_client/.tmp/message_client1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5DBus.so /usr/lib/x86_64-linux-gnu/libQt5Network.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so -lpthread -ltbb -lpaho-mqtt3as -lpaho-mqttpp3 -lmysqlcppconn -lcppunit
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

#compliers
NAME = message_client
MESSAGE_CLIENT = MessageClient
DATABASE_ADAPTER = DatabaseAdapter
PAYLOAD_OBJECT = Payload
CONFIG_MANAGER = ConfigManager
MESSAGE_NODE = MessageNode
MESSAGE_PAYLOADMAP = MessagePayloadMap
USER = User
EXTENSION_METHODS = AlgorithmProvider
CLICKABLE_LABEL = ClickableLabel
MESSAGE_EDITOR = MessageEditor
DIALOG = dialog 

#complier moc
MOC_DIALOG = moc_dialog

####### Output directory

OBJECTS_DIR   = ./

####### Folders
OBJDIR = $(mkfile_dir)obj
BINDIR = $(mkfile_dir)bin
SRCDIR = $(mkfile_dir)src
FORMDIR = $(mkfile_dir)form
METADIR = $(mkfile_dir)meta
OBJS = $(OBJDIR)/$(NAME).o

MESSAGE_CLIENT_OBJ = $(OBJDIR)/$(MESSAGE_CLIENT)
DATABASE_ADAPTER_OBJ = $(OBJDIR)/$(DATABASE_ADAPTER)
PAYLOAD_OBJECT_OBJ = $(OBJDIR)/$(PAYLOAD_OBJECT)
CONFIG_MANAGER_OBJ = $(OBJDIR)/$(CONFIG_MANAGER)
MESSAGE_NODE_OBJ = $(OBJDIR)/$(MESSAGE_NODE)
USER_OBJ = $(OBJDIR)/$(USER)
EXTENSION_METHODS_OBJ = $(OBJDIR)/$(EXTENSION_METHODS)
DIALOG_OBJ = $(OBJDIR)/$(DIALOG)
MESSAGE_PAYLOADMAP_OBJ = $(OBJDIR)/$(MESSAGE_PAYLOADMAP)
CLICKABLE_LABEL_OBJ = $(OBJDIR)/$(CLICKABLE_LABEL)
MESSAGE_EDITOR_OBJ = $(OBJDIR)/$(MESSAGE_EDITOR)

#MOC OBJ
MOC_DIALOG_OBJ = $(OBJDIR)/$(MOC_DIALOG)


$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p $(BINDIR))

####### Files

OBJECTS = $(OBJDIR)/main.o \
		$(OBJDIR)/MessageClient.o \
		$(OBJDIR)/Payload.o \
		$(OBJDIR)/MessageNode.o \
		$(OBJDIR)/DatabaseAdapter.o \
		$(OBJDIR)/User.o \
		$(OBJDIR)/AlgorithmProvider.o \
		$(OBJDIR)/ConfigManager.o \
		$(OBJDIR)/chat.o \
		$(OBJDIR)/login.o \
		$(OBJDIR)/MessageArrived.o \
		$(OBJDIR)/MessagePayloadMap.o \
		$(OBJDIR)/ClickableLabel.o \
		$(OBJDIR)/MessageEditor.o \
		$(OBJDIR)/moc_chat.o \
		$(OBJDIR)/moc_login.o \
		$(OBJDIR)/moc_message_arrived.o \
		$(OBJDIR)/moc_clickable_label.o \
		$(OBJDIR)/moc_message_editor.o 
FORMS = $(METADIR)/ui_chatmainwindow.h \
		$(METADIR)/ui_chatloginregister.h \
		$(METADIR)/ui_chatmessageeditor.h 
TESTS = $(OBJDIR)/TestSuite.o \
		$(OBJDIR)/AlgorithmProviderTest.o \
		$(OBJDIR)/ReportAlgorithmTest.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbuscommon.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusinterfaces.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusadaptors.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		message_client.pro $(COMMON_ROOT)src/layout/chat.h $(COMMON_ROOT)src/layout/chat.cpp \
		$(COMMON_ROOT)src/layout/MessageArrived.h $(COMMON_ROOT)src/layout/MessageArrived.cpp \
		$(COMMON_ROOT)src/layout/ClickableLabel.h $(COMMON_ROOT)src/layout/ClickableLabel.cpp \
		$(COMMON_ROOT)src/main.cpp
QMAKE_TARGET  = message_client
DESTDIR       = 
TARGET        = $(BINDIR)/message_client
TEST_TARGET        = $(BINDIR)/message_test


first: all
####### Build rules

$(BINDIR)/message_client:  $(FORMS) $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: message_client.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbuscommon.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusinterfaces.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusadaptors.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		message_client.pro
	$(QMAKE) -o Makefile message_client.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbuscommon.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusinterfaces.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/dbusadaptors.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
message_client.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile message_client.pro

qmake_all: FORCE


all: Makefile $(BINDIR)/message_client

TestSuite: Makefile $(BINDIR)/message_test

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents chat.h $(DISTDIR)/
	$(COPY_FILE) --parents chat.cpp $(DISTDIR)/
	$(COPY_FILE) --parents chatmainwindow.ui chatloginregister.ui chatmessageeditor.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(FORMS)
	-$(DEL_FILE) $(TESTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_message_arrived_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: $(METADIR)/moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) $(METADIR)/moc_predefs.h
$(METADIR)/moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -W -dM -E -o $(METADIR)/moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: $(METADIR)/moc_chat.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) $(METADIR)/moc_chat.cpp
$(METADIR)/moc_chat.cpp: $(COMMON_ROOT)src/layout/chat.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h $(METADIR)/moc_predefs.h /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include $(COMMON_ROOT)/$(METADIR)/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/$(COMMON_ROOT)/basiclayouts -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include $(COMMON_ROOT)src/layout/chat.h -o $(METADIR)/moc_chat.cpp

compiler_moc_login_header_make_all: $(METADIR)/moc_login.cpp
compiler_moc_login_header_clean:
	-$(DEL_FILE) $(METADIR)/moc_login.cpp
$(METADIR)/moc_login.cpp: $(COMMON_ROOT)src/layout/login.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h $(METADIR)/moc_predefs.h /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include $(COMMON_ROOT)/$(METADIR)/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/$(COMMON_ROOT)/basiclayouts -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include $(COMMON_ROOT)src/layout/login.h -o $(METADIR)/moc_login.cpp

compiler_moc_message_arrived_header_make_all: $(METADIR)/moc_message_arrived.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) $(METADIR)/moc_message_arrived.cpp
$(METADIR)/moc_message_arrived.cpp: $(COMMON_ROOT)src/layout/MessageArrived.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h $(METADIR)/moc_predefs.h /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include $(COMMON_ROOT)/$(METADIR)/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/$(COMMON_ROOT)/basiclayouts -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include $(COMMON_ROOT)src/layout/MessageArrived.h -o $(METADIR)/moc_message_arrived.cpp

compiler_moc_clickable_label_header_make_all: $(METADIR)/moc_clickable_label.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) $(METADIR)/moc_clickable_label.cpp
$(METADIR)/moc_clickable_label.cpp: $(COMMON_ROOT)src/layout/ClickableLabel.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h $(METADIR)/moc_predefs.h /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include $(COMMON_ROOT)/$(METADIR)/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/$(COMMON_ROOT)/basiclayouts -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include $(COMMON_ROOT)src/layout/ClickableLabel.h -o $(METADIR)/moc_clickable_label.cpp

compiler_moc_message_editor_header_make_all: $(METADIR)/moc_message_editor.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) $(METADIR)/moc_message_editor.cpp
$(METADIR)/moc_message_editor.cpp: $(COMMON_ROOT)src/layout/MessageEditor.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h $(METADIR)/moc_predefs.h /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include $(COMMON_ROOT)/$(METADIR)/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/$(COMMON_ROOT)/basiclayouts -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include $(COMMON_ROOT)src/layout/MessageEditor.h -o $(METADIR)/moc_message_editor.cpp

compiler_uic_make_all: $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
compiler_uic_clean:
	-$(DEL_FILE) $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h

$(METADIR)/ui_chatmainwindow.h: $(FORMDIR)/chatmainwindow.ui /usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic $(FORMDIR)/chatmainwindow.ui -o $(METADIR)/ui_chatmainwindow.h

$(METADIR)/ui_chatloginregister.h: $(FORMDIR)/chatloginregister.ui /usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic $(FORMDIR)/chatloginregister.ui -o $(METADIR)/ui_chatloginregister.h
	
$(METADIR)/ui_chatmessageeditor.h: $(FORMDIR)/chatmessageeditor.ui /usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic $(FORMDIR)/chatmessageeditor.ui -o $(METADIR)/ui_chatmessageeditor.h

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

$(OBJDIR)/chat.o: $(COMMON_ROOT)src/layout/chat.cpp $(COMMON_ROOT)src/layout/chat.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/chat.o $(COMMON_ROOT)src/layout/chat.cpp

$(OBJDIR)/login.o: $(COMMON_ROOT)src/layout/login.cpp $(COMMON_ROOT)src/layout/login.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/login.o $(COMMON_ROOT)src/layout/login.cpp

$(OBJDIR)/MessageArrived.o: $(COMMON_ROOT)src/layout/MessageArrived.cpp $(COMMON_ROOT)src/layout/MessageArrived.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/MessageArrived.o $(COMMON_ROOT)src/layout/MessageArrived.cpp
	
$(CLICKABLE_LABEL_OBJ).o:  $(COMMON_ROOT)src/layout/ClickableLabel.cpp $(COMMON_ROOT)src/layout/ClickableLabel.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/ClickableLabel.o $(COMMON_ROOT)src/layout/ClickableLabel.cpp
	
$(MESSAGE_EDITOR_OBJ).o:  $(COMMON_ROOT)src/layout/MessageEditor.cpp $(COMMON_ROOT)src/layout/MessageEditor.h $(METADIR)/ui_chatmainwindow.h $(METADIR)/ui_chatloginregister.h $(METADIR)/ui_chatmessageeditor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/MessageEditor.o $(COMMON_ROOT)src/layout/MessageEditor.cpp

$(OBJDIR)/main.o: $(COMMON_ROOT)src/main.cpp $(COMMON_ROOT)src/layout/chat.h $(COMMON_ROOT)src/layout/MessageArrived.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/main.o $(COMMON_ROOT)src/main.cpp

$(OBJDIR)/moc_chat.o: $(METADIR)/moc_chat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/moc_chat.o $(METADIR)/moc_chat.cpp

$(OBJDIR)/moc_login.o: $(METADIR)/moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/moc_login.o $(METADIR)/moc_login.cpp
	
$(OBJDIR)/moc_message_arrived.o: $(METADIR)/moc_message_arrived.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/moc_message_arrived.o $(METADIR)/moc_message_arrived.cpp
	
$(OBJDIR)/moc_clickable_label.o: $(METADIR)/moc_clickable_label.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/moc_clickable_label.o $(METADIR)/moc_clickable_label.cpp
	
$(OBJDIR)/moc_message_editor.o: $(METADIR)/moc_message_editor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/moc_message_editor.o $(METADIR)/moc_message_editor.cpp

$(MESSAGE_CLIENT_OBJ).o: $(COMMON_ROOT)src/MessageClient.cpp $(COMMON_ROOT)src/MessageClient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/MessageClient.o $(COMMON_ROOT)src/MessageClient.cpp

$(MESSAGE_PAYLOADMAP_OBJ).o:  $(COMMON_ROOT)src/layout/MessagePayloadMap.cpp $(COMMON_ROOT)src/layout/MessagePayloadMap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/MessagePayloadMap.o $(COMMON_ROOT)src/layout/MessagePayloadMap.cpp
	
####### Common complie

$(PAYLOAD_OBJECT_OBJ).o: $(MESSAGE_COMMON_ROOT)src/Payload.cpp $(MESSAGE_COMMON_ROOT)src/Payload.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/Payload.o $(MESSAGE_COMMON_ROOT)src/Payload.cpp
	
$(DATABASE_ADAPTER_OBJ).o: $(MESSAGE_COMMON_ROOT)src/DatabaseAdapter.cpp $(MESSAGE_COMMON_ROOT)src/DatabaseAdapter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/DatabaseAdapter.o $(MESSAGE_COMMON_ROOT)src/DatabaseAdapter.cpp
	
$(USER_OBJ).o: $(MESSAGE_COMMON_ROOT)src/User.cpp $(MESSAGE_COMMON_ROOT)src/User.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/User.o $(MESSAGE_COMMON_ROOT)src/User.cpp
	
$(EXTENSION_METHODS_OBJ).o: $(MESSAGE_COMMON_ROOT)src/AlgorithmProvider.cpp $(MESSAGE_COMMON_ROOT)src/AlgorithmProvider.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/AlgorithmProvider.o $(MESSAGE_COMMON_ROOT)src/AlgorithmProvider.cpp
	
$(CONFIG_MANAGER_OBJ).o: $(MESSAGE_COMMON_ROOT)src/ConfigManager.cpp $(MESSAGE_COMMON_ROOT)src/ConfigManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/ConfigManager.o $(MESSAGE_COMMON_ROOT)src/ConfigManager.cpp
	
$(MESSAGE_NODE_OBJ).o: $(MESSAGE_COMMON_ROOT)src/MessageNode.cpp $(MESSAGE_COMMON_ROOT)src/MessageNode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/MessageNode.o $(MESSAGE_COMMON_ROOT)src/MessageNode.cpp

###### Tests

$(BINDIR)/message_test:  $(OBJECTS) $(TESTS)
	$(LINK) $(LFLAGS) -o $(TEST_TARGET) $(OBJDIR)/MessageClient.o \
		$(OBJDIR)/Payload.o \
		$(OBJDIR)/MessageNode.o \
		$(OBJDIR)/DatabaseAdapter.o \
		$(OBJDIR)/User.o \
		$(OBJDIR)/AlgorithmProvider.o \
		$(OBJDIR)/ConfigManager.o \
		$(OBJDIR)/chat.o \
		$(OBJDIR)/login.o \
		$(OBJDIR)/MessageArrived.o \
		$(OBJDIR)/MessagePayloadMap.o \
		$(OBJDIR)/ClickableLabel.o \
		$(OBJDIR)/MessageEditor.o \
		$(OBJDIR)/moc_chat.o \
		$(OBJDIR)/moc_login.o \
		$(OBJDIR)/moc_message_arrived.o \
		$(OBJDIR)/moc_clickable_label.o \
		$(OBJDIR)/moc_message_editor.o $(OBJDIR)/TestSuite.o $(OBJCOMP) $(LIBS)
	
$(OBJDIR)/TestSuite.o: $(COMMON_ROOT)test/TestSuite.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/TestSuite.o $(COMMON_ROOT)test/TestSuite.cpp

$(OBJDIR)/AlgorithmProviderTest.o: $(COMMON_ROOT)test/AlgorithmProviderTest.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/AlgorithmProviderTest.o $(COMMON_ROOT)test/AlgorithmProviderTest.cpp
	
$(OBJDIR)/ReportAlgorithmTest.o: $(COMMON_ROOT)test/ReportAlgorithmTest.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $(OBJDIR)/ReportAlgorithmTest.o $(COMMON_ROOT)test/ReportAlgorithmTest.cpp
 