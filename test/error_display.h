
#ifndef ERROR_DISPLAY_H
#define ERROR_DISPLAY_H

struct xqp::ZorbaAlert;
struct xqp::ZorbaErrorAlert;
struct xqp::ZorbaWarningAlert;
struct xqp::ZorbaNotifyAlert;
struct xqp::ZorbaAskUserAlert;
struct xqp::ZorbaFnErrorAlert;
struct xqp::ZorbaFnTraceAlert;

extern void DisplayErrorListForCurrentThread();

extern void DisplayOneAlert(const xqp::ZorbaAlert *alert);
extern void DisplayError(const xqp::ZorbaErrorAlert *err);
extern void DisplayWarning(const xqp::ZorbaWarningAlert *warn);
extern void DisplayNotification(const xqp::ZorbaNotifyAlert *notif);
extern int DisplayAskUser(const xqp::ZorbaAskUserAlert *askuser);
extern void DisplayFnUserError(const xqp::ZorbaFnErrorAlert *fn_err);
extern void DisplayFnUserTrace(const xqp::ZorbaFnTraceAlert *fn_trace);

#endif
