/****************************************************************************
**
** Copyright (C) 2019 BlackINT3
** Contact: https://github.com/BlackINT3/OpenArk
**
** GNU Lesser General Public License Usage (LGPL)
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/
#pragma once
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QMutex>
#include <qbuttongroup.h>
#include <Windows.h>
#include <mutex>
#include "ui_coderkit.h"
#include "../common/ui-wrapper/ui-wrapper.h"

namespace Ui {
	class CoderKit;
	class OpenArkWindow;
}

class OpenArk;

class CoderKit : public CommonMainTabObject {
	Q_OBJECT
public:
	CoderKit(QWidget* parent, int tabid);
	~CoderKit();

private slots:
	void onTabChanged(int index);
	void onCodeTextChanged();
	void onCodeTextChanged(const QString &text);
	void onWindowsErrorTextChanged(const QString &text);
	void onMessageId();
	void onAlgIndexChanged(int index);
	void onAlgPlainChanged();
	void onFormatChanged();

private:
	void InitAsmToolsView();

	void UpdateAlgorithmText(bool crypt);
	void UpdateEditCodeText(const std::wstring& data, QObject* ignored_obj);
	QString Rasm2Asm(std::string data, int cpu, int byteorder, const std::string &format);
	QString Rasm2Disasm(std::string data, int cpu, int byteorder);
	QString NasmAsm(std::string data, int bits, const std::string &format);
	QString NasmDisasm(const std::string &data, int bits);
	void SolveCodeTextFormat(std::string &text, std::string &format, int interval, int id);
	std::string UrlEncode(const std::string &buf, std::vector<char> pass);
	std::string UrlDecode(const std::string &buf);
	std::string UrlEncodeURL(const std::string &buf);

private:
	Ui::CoderKit ui;
	std::mutex upt_mutex_;
	int alg_idx_;
	bool is_user_;
	bool is_format_changed_;
	QButtonGroup radio_group_type_;
	QButtonGroup radio_group_interval_;
};