
#ifndef ERROR_DISPLAY_H
#define ERROR_DISPLAY_H

struct xqp::Zorba_AlertMessage;
struct xqp::Zorba_ErrorMessage;
struct xqp::Zorba_WarningMessage;
struct xqp::Zorba_NotifyMessage;
struct xqp::Zorba_AskUserMessage;
struct xqp::Zorba_FnErrorMessage;
struct xqp::Zorba_FnTraceMessage;

extern void DisplayErrorListForCurrentThread();

extern void DisplayOneAlert(const xqp::Zorba_AlertMessage *alert);
extern void DisplayError(const xqp::Zorba_ErrorMessage *err);
extern void DisplayWarning(const xqp::Zorba_WarningMessage *warn);
extern void DisplayNotification(const xqp::Zorba_NotifyMessage *notif);
extern int DisplayAskUser(const xqp::Zorba_AskUserMessage *askuser);
extern void DisplayFnUserError(const xqp::Zorba_FnErrorMessage *fn_err);
extern void DisplayFnUserTrace(const xqp::Zorba_FnTraceMessage *fn_trace);

#endif
