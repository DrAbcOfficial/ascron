#include "libcron/Cron.h"
#include "CASCron.h"

CASCron g_pASCron;
libcron::Cron cron;
void CASCron::Add(CString* name, CString* time, void* callback, void* any){
	auto scriptFunction = [=](auto& i) {
		aslScriptFunction* pfnASCallBack = static_cast<aslScriptFunction*>(callback);
		CASFunction* m_callback = ASEXT_CreateCASFunction(pfnASCallBack, ASEXT_GetServerManager()->curModule, 1);
		(*ASEXT_CallCASBaseCallable)(m_callback, 0, name, time, any);
	};
	cron.add_schedule(name->c_str(), time->c_str(), scriptFunction);
}

void CASCron::AddWithoutParam(CString* name, CString* time, void* callback) {
	auto scriptFunction = [=](auto& i) {
		aslScriptFunction* pfnASCallBack = static_cast<aslScriptFunction*>(callback);
		CASFunction* m_callback = ASEXT_CreateCASFunction(pfnASCallBack, ASEXT_GetServerManager()->curModule, 1);
		(*ASEXT_CallCASBaseCallable)(m_callback, 0, name, time);
	};
	cron.add_schedule(name->c_str(), time->c_str(), scriptFunction);
}

void CASCron::Remove(CString* str){
	cron.remove_schedule(str->c_str());
}

void CASCron::RemoveAll(){
	cron.clear_schedules();
}

size_t CASCron::Count(){
	return cron.count();
}

void CASCron::Tick(){
	cron.tick();
}
