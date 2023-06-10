#pragma once
#include "CASBaseObject.h"
class CASCron {
public:
	void Add(CString* name, CString* time, void* callback, void* any);
	void AddWithoutParam(CString* name, CString* time, void* callback);
	void Remove(CString* str);
	void RemoveAll();

	size_t Count();

	void Tick();
};
extern CASCron g_pASCron;