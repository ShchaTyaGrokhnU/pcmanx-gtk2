#ifndef SCRIPT_API_H
#define SCRIPT_API_H

#ifdef __cplusplus
extern "C" {
#endif

void InitScriptInterface(char *path);
void ScriptOnNewIncomingMessage(void *handle, char *text);
void FinalizeScriptInterface();

#ifdef __cplusplus
}
#endif

#endif /* SCRIPT_API_H */
