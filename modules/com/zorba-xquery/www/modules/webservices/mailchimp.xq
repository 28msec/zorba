(:~
 :
 : Mailchimp Client Module.
 :
 : @see <a href="http://apidocs.mailchimp.com" target="_blank">http://apidocs.mailchimp.com</a>
 :
 : @author William Candillon {william.candillon@28msec.com}
 :
 :)
module namespace mailchimp = "http://www.zorba-xquery.com/modules/webservices/mailchimp";

import module namespace http-client = "http://expath.org/ns/http-client";

import module namespace xmlrpc = "http://www.zorba-xquery.com/modules/xmlrpc";

(:~
 : Mailchimp gateway where the client data is stored.
 :)
declare variable $mailchimp:gateway  := "us2";

(:~
 : Mailchimp API version.
 :)
declare variable $mailchimp:version  := "1.3";

(:~
 : Endpoint URL for the XML-RPC requests.
 :)
declare variable $mailchimp:endpoint := concat("http://", $mailchimp:gateway, ".api.mailchimp.com/", $mailchimp:version, "/");

(:~
 :
 : Convenience function for <a href='#campaign-unschedule-3'>campaign-unschedule#3</a>.
 :
 : @see <a href='#campaign-unschedule-3'>campaign-unschedule#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to unschedule
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-unschedule($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-unschedule($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Unschedule a campaign that is scheduled to be sent in the future.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignunschedule.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to unschedule
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-unschedule($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignUnschedule", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-schedule-5'>campaign-schedule#5</a>.
 :
 : @see <a href='#campaign-schedule-5'>campaign-schedule#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to schedule
 : @param $schedule_time the time to schedule the campaign. For A/B Split "schedule" campaigns, the time for Group A - in YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 : @param $schedule_time_b optional -the time to schedule Group B of an A/B Split "schedule" campaign - in YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return boolean True on success
 :)
declare sequential function mailchimp:campaign-schedule($apikey as xs:string, $cid as xs:string, $schedule_time as xs:string, $schedule_time_b as xs:string){
  mailchimp:campaign-schedule($mailchimp:endpoint, $apikey, $cid, $schedule_time, $schedule_time_b)
};

(:~
 : Schedule a campaign to be sent in the future.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignschedule.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to schedule
 : @param $schedule_time the time to schedule the campaign. For A/B Split "schedule" campaigns, the time for Group A - in YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 : @param $schedule_time_b optional -the time to schedule Group B of an A/B Split "schedule" campaign - in YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return boolean True on success
 :)
declare sequential function mailchimp:campaign-schedule($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $schedule_time as xs:string, $schedule_time_b as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignSchedule", ($apikey, $cid, $schedule_time, $schedule_time_b))
};

(:~
 :
 : Convenience function for <a href='#campaign-resume-3'>campaign-resume#3</a>.
 :
 : @see <a href='#campaign-resume-3'>campaign-resume#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to pause
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-resume($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-resume($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Resume sending an AutoResponder or RSS campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignresume.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to pause
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-resume($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignResume", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-pause-3'>campaign-pause#3</a>.
 :
 : @see <a href='#campaign-pause-3'>campaign-pause#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to pause
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-pause($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-pause($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Pause an AutoResponder or RSS campaign from sending.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignpause.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to pause
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-pause($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignPause", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-send-now-3'>campaign-send-now#3</a>.
 :
 : @see <a href='#campaign-send-now-3'>campaign-send-now#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to send
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-send-now($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-send-now($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Send a given campaign immediately. For RSS campaigns, this will "start" them.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsendnow.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to send
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-send-now($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignSendNow", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-send-test-5'>campaign-send-test#5</a>.
 :
 : @see <a href='#campaign-send-test-5'>campaign-send-test#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the id of the campaign to test
 : @param $test_emails an array of email address to receive the test message
 : @param $send_type optional by default (null) both formats are sent - "html" or "text" send just that format
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-send-test($apikey as xs:string, $cid as xs:string, $test_emails as element(array), $send_type as xs:string){
  mailchimp:campaign-send-test($mailchimp:endpoint, $apikey, $cid, $test_emails, $send_type)
};

(:~
 : Send a test of this campaign to the provided email address.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsendtest.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the id of the campaign to test
 : @param $test_emails an array of email address to receive the test message
 : @param $send_type optional by default (null) both formats are sent - "html" or "text" send just that format
 :
 : @return True on success
 :)
declare sequential function mailchimp:campaign-send-test($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $test_emails as element(array), $send_type as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignSendTest", ($apikey, $cid, $test_emails, $send_type))
};

(:~
 :
 : Convenience function for <a href='#campaign-segment-test-4'>campaign-segment-test#4</a>.
 :
 : @see <a href='#campaign-segment-test-4'>campaign-segment-test#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $list_id the list to test segmentation on - get lists using lists()
 : @param $options with 2 keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaignsegmenttest.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return The total number of subscribers matching your segmentation options
 :)
declare sequential function mailchimp:campaign-segment-test($apikey as xs:string, $list_id as xs:string, $options as element(array)){
  mailchimp:campaign-segment-test($mailchimp:endpoint, $apikey, $list_id, $options)
};

(:~
 :
 : Allows one to test their segmentation rules before creating a campaign using them.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsegmenttest.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $list_id the list to test segmentation on - get lists using <a href="#lists-4">lists()</a>
 : @param $options with 2 keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaignsegmenttest.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return The total number of subscribers matching your segmentation options
 :)
declare sequential function mailchimp:campaign-segment-test($endpoint-url as xs:string, $apikey as xs:string, $list_id as xs:string, $options as element(array)){
  xmlrpc:invoke($endpoint-url, "campaignSegmentTest", ($apikey, $list_id, $options))
};

(:~
 :
 : Convenience function for <a href='#campaign-create-7'>campaign-create#7</a>.
 :
 : @see <a href='#campaign-create-7'>campaign-create#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $type the Campaign Type to create - one of "regular", "plaintext", "absplit", "rss", "trans", "auto"
 : @param $options a hash of the standard options for this campaign. See <a href='http://apidocs.mailchimp.com/rtfm/campaigncreate.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $content the content for this campaign - use a struct with the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaigncreate.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $segment_opts optional - if you wish to do Segmentation with this campaign this array should contain: see <a href="#campaign-segment-test-3">campaign-segment-test()</a>. It's suggested that you test your options against <a href="#campaign-segment-test-3">campaign-segment-test()</a>. Also, "trans" campaigns <strong>do not</strong> support segmentation.
 : @param $type_opts optional -
 :
 : @return The ID for the created campaign
 :)
declare sequential function mailchimp:campaign-create($apikey as xs:string, $type as xs:string, $options as element(array), $content as element(array), $segment_opts as element(array), $type_opts as element(array)){
  mailchimp:campaign-create($mailchimp:endpoint, $apikey, $type, $options, $content, $segment_opts, $type_opts)
};

(:~
 :
 : Create a new draft campaign to send. You can not have more than 32,000 campaigns in your account. 
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigncreate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $type the Campaign Type to create - one of "regular", "plaintext", "absplit", "rss", "trans", "auto"
 : @param $options a hash of the standard options for this campaign. See <a href='http://apidocs.mailchimp.com/rtfm/campaigncreate.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $content the content for this campaign - use a struct with the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaigncreate.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $segment_opts optional - if you wish to do Segmentation with this campaign this array should contain: see <a href="#campaign-segment-test-3"><a href="#campaign-segment-test-3">campaign-segment-test()</a></a>. It's suggested that you test your options against <a href="#campaign-segment-test-3">campaign-segment-test()</a>. Also, "trans" campaigns <strong>do not</strong> support segmentation.
 : @param $type_opts optional
 :
 : @return The ID for the created campaign
 :)
declare sequential function mailchimp:campaign-create($endpoint-url as xs:string, $apikey as xs:string, $type as xs:string, $options as element(array), $content as element(array), $segment_opts as element(array), $type_opts as element(array)){
  xmlrpc:invoke($endpoint-url, "campaignCreate", ($apikey, $type, $options, $content, $segment_opts, $type_opts))
};

(:~
 :
 : Convenience function for <a href='#campaign-update-5'>campaign-update#5</a>.
 :
 : @see <a href='#campaign-update-5'>campaign-update#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the Campaign Id to update
 : @param $name the parameter name (see <a href="#campaign-create-6">campaigncreate()</a>). For items in the <strong>options</strong> array, this will be that parameter's name (subject, from_email, etc.). Additional parameters will be that option name (content, segment_opts). "type_opts" will be the name of the type - rss, auto, trans, etc.
 : @param $value e an appropriate value for the parameter ( see <a href="#campaign-create-6">campaigncreate()</a>). For items in the <strong>options</strong> array, this will be that parameter's value. For additional parameters, this is the same value passed to them.
 :
 : @return boolean true if the update succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-update($apikey as xs:string, $cid as xs:string, $name as xs:string, $value as item()){
  mailchimp:campaign-update($mailchimp:endpoint, $apikey, $cid, $name, $value)
};

(:~
 : Update just about any setting for a campaign that has <em>not</em> been sent. See <a href="#campaign-create-6">campaigncreate()</a> for details.
 : Caveats: <br/>
 :  <ul>
 :    <li>If you set list_id, all segmentation options will be deleted and must be re-added.</li>
 :    <li>If you set template_id, you need to follow that up by setting it's 'content'</li>
 :    <li>If you set segment_opts, you should have tested your options against <a href="#campaign-segment-test-3">campaign-segment-test()</a> as <a href="#campaign-update-4">campaign-update()</a> will not allow you to set a segment that includes no members.</li>
 :  </ul>.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the Campaign Id to update
 : @param $name the parameter name ( see <a href="#campaign-create-6">campaigncreate()</a>). For items in the <strong>options</strong> array, this will be that parameter's name (subject, from_email, etc.). Additional parameters will be that option name (content, segment_opts). "type_opts" will be the name of the type - rss, auto, trans, etc.
 : @param $value An appropriate value for the parameter ( see <a href="#campaign-create-6">campaigncreate()</a>). For items in the <strong>options</strong> array, this will be that parameter's value. For additional parameters, this is the same value passed to them.
 :
 : @return True if the update succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-update($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $name as xs:string, $value as item()){
  xmlrpc:invoke($endpoint-url, "campaignUpdate", ($apikey, $cid, $name, $value))
};

(:~
 :
 : Convenience function for <a href='#campaign-replicate-3'>campaign-replicate#3</a>.
 :
 : @see <a href='#campaign-replicate-3'>campaign-replicate#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the Campaign Id to replicate
 :
 : @return The id of the replicated Campaign created, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-replicate($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-replicate($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Replicate a campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignreplicate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the Campaign Id to replicate
 :
 : @return The id of the replicated Campaign created, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-replicate($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignReplicate", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-delete-3'>campaign-delete#3</a>.
 :
 : @see <a href='#campaign-delete-3'>campaign-delete#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the Campaign Id to delete
 :
 : @return True if the delete succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-delete($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-delete($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Delete a campaign. Seriously, "poof, gone!" - be careful!.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigndelete.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the Campaign Id to delete
 :
 : @return True if the delete succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:campaign-delete($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignDelete", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaigns-5'>campaigns#5</a>.
 :
 : @see <a href='#campaigns-5'>campaigns#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $filters a hash of filters to apply to this query - all are optional. See <a href='http://apidocs.mailchimp.com/rtfm/campaigns.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $start optional - control paging of campaigns, start results at this campaign #, defaults to 1st page of data (page 0)
 : @param $limit optional - control paging of campaigns, number of campaigns to return with each call, defaults to 25 (max=1000)
 :
 : @return An array containing a count of all matching campaigns and the specific ones for the current page (see <a href='http://apidocs.mailchimp.com/rtfm/campaigns.func.php'>Mailchimp API documentation</a> for more information about the return type)
 :)
declare sequential function mailchimp:campaigns($apikey as xs:string, $filters as element(array), $start as xs:integer, $limit as xs:integer){
  mailchimp:campaigns($mailchimp:endpoint, $apikey, $filters, $start, $limit)
};

(:~
 :
 : Get the list of campaigns and their details matching the specified filters.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigns.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $filters a hash of filters to apply to this query - all are optional. See <a href='http://apidocs.mailchimp.com/rtfm/campaigns.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $start optional - control paging of campaigns, start results at this campaign #, defaults to 1st page of data (page 0)
 : @param $limit optional - control paging of campaigns, number of campaigns to return with each call, defaults to 25 (max=1000)
 :
 : @return An array containing a count of all matching campaigns and the specific ones for the current page (see <a href='http://apidocs.mailchimp.com/rtfm/campaigns.func.php'>Mailchimp API documentation</a> for more information about the return type)
 :)
declare sequential function mailchimp:campaigns($endpoint-url as xs:string, $apikey as xs:string, $filters as element(array), $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaigns", ($apikey, $filters, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-stats-3'>campaign-stats#3</a>.
 :
 : @see <a href='#campaign-stats-3'>campaign-stats#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return array struct of the statistics for this campaign
 :)
declare sequential function mailchimp:campaign-stats($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-stats($mailchimp:endpoint, $apikey, $cid)
};

(:~
 :
 : Given a list and a campaign, get all the relevant campaign statistics (opens, bounces, clicks, etc.)
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignstats.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return array struct of the statistics for this campaign
 :)
declare sequential function mailchimp:campaign-stats($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignStats", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-click-stats-3'>campaign-click-stats#3</a>.
 :
 : @see <a href='#campaign-click-stats-3'>campaign-click-stats#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return URLs will be keys and contain their associated statistics: clicks (number of times a specific link was clicked) and unique (number of unique people who clicked on the specific link).
 :)
declare sequential function mailchimp:campaign-click-stats($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-click-stats($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Get an array of the urls being tracked, and their click counts for a given campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignclickstats.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return URLs will be keys and contain their associated statistics: clicks (number of times a specific link was clicked) and unique (number of unique people who clicked on the specific link).
 :)
declare sequential function mailchimp:campaign-click-stats($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignClickStats", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-email-domain-performance-3'>campaign-email-domain-performance#3</a>.
 :
 : @see <a href='#campaign-email-domain-performance-3'>campaign-email-domain-performance#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull email domain performance for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Domains email domains and their associated stats
 :)
declare sequential function mailchimp:campaign-email-domain-performance($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-email-domain-performance($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Get the top 5 performing email domains for this campaign. Users want more than 5 should use campaign <a href="#campaign-email-stats-AIM-3">campaign-email-stats-AIM()</a> or <a href='#campaign-email-stats-AIM-all-4'>campaign-email-stats-AIM-all()</a> and generate any additional stats they require.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignemaildomainperformance.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull email domain performance for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Domains email domains and their associated stats
 :)
declare sequential function mailchimp:campaign-email-domain-performance($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignEmailDomainPerformance", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-members-6'>campaign-members#6</a>.
 :
 : @see <a href='#campaign-members-6'>campaign-members#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull members for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $status optional the status to pull - one of 'sent', 'hard' (bounce), or 'soft' (bounce). By default, all records are returned
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return A total of all matching emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-members($apikey as xs:string, $cid as xs:string, $status as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-members($mailchimp:endpoint, $apikey, $cid, $status, $start, $limit)
};

(:~
 : Get all email addresses the campaign was successfully sent to (ie, no bounces).
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignmembers.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull members for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $status optional the status to pull - one of 'sent', 'hard' (bounce), or 'soft' (bounce). By default, all records are returned
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return A total of all matching emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-members($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $status as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignMembers", ($apikey, $cid, $status, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-hard-bounces-5'>campaign-hard-bounces#5</a>.
 :
 : @see <a href='#campaign-hard-bounces-5'>campaign-hard-bounces#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return array a total of all hard bounced emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-hard-bounces($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-hard-bounces($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : <strong>DEPRECATED</strong> Get all email addresses with Hard Bounces for a given campaign the email address that bounced.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignhardbounces.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return array a total of all hard bounced emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-hard-bounces($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignHardBounces", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-soft-bounces-5'>campaign-soft-bounces#5</a>.
 :
 : @see <a href='#campaign-soft-bounces-5'>campaign-soft-bounces#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return A total of all soft bounced emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-soft-bounces($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-soft-bounces($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : <strong>DEPRECATED</strong> Get all email addresses with Soft Bounces for a given campaign the email address that bounced.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsoftbounces.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return A total of all soft bounced emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-soft-bounces($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignSoftBounces", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-unsubscribes-5'>campaign-unsubscribes#5</a>.
 :
 : @see <a href='#campaign-unsubscribes-5'>campaign-unsubscribes#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return array email addresses that unsubscribed from this campaign along with reasons, if given array a total of all unsubscribed emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-unsubscribes($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-unsubscribes($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : Get all unsubscribed email addresses for a given campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignunsubscribes.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return array email addresses that unsubscribed from this campaign along with reasons, if given array a total of all unsubscribed emails and the specific emails for this page
 :)
declare sequential function mailchimp:campaign-unsubscribes($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignUnsubscribes", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-abuse-reports-6'>campaign-abuse-reports#6</a>.
 :
 : @see <a href='#campaign-abuse-reports-6'>campaign-abuse-reports#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull abuse reports for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $since optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $start optional for large data sets, the number of results to return - defaults to 500, upper limit set at 1000
 : @param $limit optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return Reports the abuse reports for this campaign
 :)
declare sequential function mailchimp:campaign-abuse-reports($apikey as xs:string, $cid as xs:string, $since as xs:integer, $start as xs:integer, $limit as xs:string){
  mailchimp:campaign-abuse-reports($mailchimp:endpoint, $apikey, $cid, $since, $start, $limit)
};

(:~
 : Get all email addresses that complained about a given campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignabusereports.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull abuse reports for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $since optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $start optional for large data sets, the number of results to return - defaults to 500, upper limit set at 1000
 : @param $limit optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return Reports the abuse reports for this campaign
 :)
declare sequential function mailchimp:campaign-abuse-reports($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $since as xs:integer, $start as xs:integer, $limit as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignAbuseReports", ($apikey, $cid, $since, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-advice-3'>campaign-advice#3</a>.
 :
 : @see <a href='#campaign-advice-3'>campaign-advice#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull advice text for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Advice on the campaign's performance
 :)
declare sequential function mailchimp:campaign-advice($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-advice($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Retrieve the text presented in our app for how a campaign performed and any advice we may have for you - best suited for display in customized reports pages.
 : Note: some messages will contain HTML - clean tags as necessary.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignadvice.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull advice text for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Advice on the campaign's performance
 :)
declare sequential function mailchimp:campaign-advice($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignAdvice", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-analytics-3'>campaign-analytics#3</a>.
 :
 : @see <a href='#campaign-analytics-3'>campaign-analytics#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Analytics we've collected for the passed campaign.
 :)
declare sequential function mailchimp:campaign-analytics($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-analytics($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Retrieve the Google Analytics data we've collected for this campaign. Note, requires Google Analytics Add-on to be installed and configured.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignanalytics.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Analytics we've collected for the passed campaign.
 :)
declare sequential function mailchimp:campaign-analytics($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignAnalytics", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-geo-opens-3'>campaign-geo-opens#3</a>.
 :
 : @see <a href='#campaign-geo-opens-3'>campaign-geo-opens#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Countries an array of countries where opens occurred
 :)
declare sequential function mailchimp:campaign-geo-opens($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-geo-opens($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Retrieve the countries and number of opens tracked for each. Email address are not returned.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigngeoopens.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Countries an array of countries where opens occurred
 :)
declare sequential function mailchimp:campaign-geo-opens($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignGeoOpens", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-geo-opens-for-country-4'>campaign-geo-opens-for-country#4</a>.
 :
 : @see <a href='#campaign-geo-opens-for-country-4'>campaign-geo-opens-for-country#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $code An ISO3166 2 digit country code
 :
 : @return Regions an array of regions within the provided country where opens occurred.
 :)
declare sequential function mailchimp:campaign-geo-opens-for-country($apikey as xs:string, $cid as xs:string, $code as xs:string){
  mailchimp:campaign-geo-opens-for-country($mailchimp:endpoint, $apikey, $cid, $code)
};

(:~
 : Retrieve the regions and number of opens tracked for a certain country. Email address are not returned.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigngeoopensforcountry.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $code An ISO3166 2 digit country code
 :
 : @return Regions an array of regions within the provided country where opens occurred.
 :)
declare sequential function mailchimp:campaign-geo-opens-for-country($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $code as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignGeoOpensForCountry", ($apikey, $cid, $code))
};

(:~
 :
 : Convenience function for <a href='#campaign-eep-url-stats-3'>campaign-eep-url-stats#3</a>.
 :
 : @see <a href='#campaign-eep-url-stats-3'>campaign-eep-url-stats#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Stats an array containing tweets, retweets, clicks, and referrer related to using the campaign's eepurl
 :)
declare sequential function mailchimp:campaign-eep-url-stats($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-eep-url-stats($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Retrieve the tracked eepurl mentions on Twitter.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigneepurlstats.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Stats an array containing tweets, retweets, clicks, and referrer related to using the campaign's eepurl
 :)
declare sequential function mailchimp:campaign-eep-url-stats($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignEepUrlStats", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-bounce-message-4'>campaign-bounce-message#4</a>.
 :
 : @see <a href='#campaign-bounce-message-4'>campaign-bounce-message#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $email the email address or unique id of the member to pull a bounce message for.
 :
 : @return The full bounce message for this email+campaign along with some extra data.
 :)
declare sequential function mailchimp:campaign-bounce-message($apikey as xs:string, $cid as xs:string, $email as xs:string){
  mailchimp:campaign-bounce-message($mailchimp:endpoint, $apikey, $cid, $email)
};

(:~
 : Retrieve the most recent full bounce message for a specific email address on the given campaign. Messages over 30 days old are subject to being removed.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignbouncemessage.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $email the email address or unique id of the member to pull a bounce message for.
 :
 : @return The full bounce message for this email+campaign along with some extra data.
 :)
declare sequential function mailchimp:campaign-bounce-message($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $email as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignBounceMessage", ($apikey, $cid, $email))
};

(:~
 :
 : Convenience function for <a href='#campaign-bounce-messages-6'>campaign-bounce-messages#6</a>.
 :
 : @see <a href='#campaign-bounce-messages-6'>campaign-bounce-messages#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 25, upper limit set at 50
 : @param $since optional pull only messages since this time - use YYYY-MM-DD format in <strong>GMT</strong> (we only store the date, not the time)
 :
 : @return Bounces the full bounce messages for this campaign
 :)
declare sequential function mailchimp:campaign-bounce-messages($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  mailchimp:campaign-bounce-messages($mailchimp:endpoint, $apikey, $cid, $start, $limit, $since)
};

(:~
 : Retrieve the full bounce messages for the given campaign. Note that this can return very large amounts of data depending on how large the campaign was and how much cruft the bounce provider returned.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignbouncemessages.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 25, upper limit set at 50
 : @param $since optional pull only messages since this time - use YYYY-MM-DD format in <strong>GMT</strong> (we only store the date, not the time)
 :
 : @return Bounces the full bounce messages for this campaign
 :)
declare sequential function mailchimp:campaign-bounce-messages($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignBounceMessages", ($apikey, $cid, $start, $limit, $since))
};

(:~
 :
 : Convenience function for <a href='#campaign-ecomm-orders-6'>campaign-ecomm-orders#6</a>.
 :
 : @see <a href='#campaign-ecomm-orders-6'>campaign-ecomm-orders#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 500
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return The total matching orders and the specific orders for the requested page
 :)
declare sequential function mailchimp:campaign-ecomm-orders($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  mailchimp:campaign-ecomm-orders($mailchimp:endpoint, $apikey, $cid, $start, $limit, $since)
};

(:~
 : Retrieve the Ecommerce Orders tracked by <a href="#campaign-ecomm-order-add-2">campaign-ecomm-order-add()</a>.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignecommorders.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to pull bounces for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 500
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return The total matching orders and the specific orders for the requested page
 :)
declare sequential function mailchimp:campaign-ecomm-orders($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignEcommOrders", ($apikey, $cid, $start, $limit, $since))
};

(:~
 :
 : Convenience function for <a href='#campaign-share-report-4'>campaign-share-report#4</a>.
 :
 : @see <a href='#campaign-share-report-4'>campaign-share-report#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to share a report for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $opts s optional various parameters which can be used to configure the shared report
 :
 : @return Struct containing details for the shared report
 :)
declare sequential function mailchimp:campaign-share-report($apikey as xs:string, $cid as xs:string, $opts as element(array)){
  mailchimp:campaign-share-report($mailchimp:endpoint, $apikey, $cid, $opts)
};

(:~
 :
 : Get the URL to a customized <a href="http://eepurl.com/gKmL" target="_blank">VIP Report</a> for the specified campaign and optionally send an email to someone with links to it. Note subsequent calls will overwrite anything already set for the same campign (eg, the password).
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsharereport.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to share a report for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $opts s optional various parameters which can be used to configure the shared report
 :
 : @return Struct containing details for the shared report
 :)
declare sequential function mailchimp:campaign-share-report($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $opts as element(array)){
  xmlrpc:invoke($endpoint-url, "campaignShareReport", ($apikey, $cid, $opts))
};

(:~
 :
 : Convenience function for <a href='#campaign-content-4'>campaign-content#4</a>.
 :
 : @see <a href='#campaign-content-4'>campaign-content#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get content for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $for_archive optional controls whether we return the Archive version (true) or the Raw version (false), defaults to true
 :
 : @return Struct containing all content for the campaign
 :)
declare sequential function mailchimp:campaign-content($apikey as xs:string, $cid as xs:string, $for_archive as xs:boolean){
  mailchimp:campaign-content($mailchimp:endpoint, $apikey, $cid, $for_archive)
};

(:~
 : Get the content (both html and text) for a campaign either as it would appear in the campaign archive or as the raw, original content.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigncontent.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get content for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $for_archive optional controls whether we return the Archive version (true) or the Raw version (false), defaults to true
 :
 : @return Struct containing all content for the campaign
 :)
declare sequential function mailchimp:campaign-content($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $for_archive as xs:boolean){
  xmlrpc:invoke($endpoint-url, "campaignContent", ($apikey, $cid, $for_archive))
};

(:~
 :
 : Convenience function for <a href='#campaign-template-content-3'>campaign-template-content#3</a>.
 :
 : @see <a href='#campaign-template-content-3'>campaign-template-content#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get content for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Array containing all content section for the campaign -
 :)
declare sequential function mailchimp:campaign-template-content($apikey as xs:string, $cid as xs:string){
  mailchimp:campaign-template-content($mailchimp:endpoint, $apikey, $cid)
};

(:~
 : Get the HTML template content sections for a campaign. Note that this <strong>will</strong> return very jagged, non-standard results based on the template a campaign is using. You only want to use this if you want to allow editing template sections in your applicaton.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaigntemplatecontent.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get content for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 :
 : @return Array containing all content section for the campaign -
 :)
declare sequential function mailchimp:campaign-template-content($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignTemplateContent", ($apikey, $cid))
};

(:~
 :
 : Convenience function for <a href='#campaign-opened-AIM-5'>campaign-openedAIM#5</a>.
 :
 : @see <a href='#campaign-opened-AIM-5'>campaign-opened-AIM#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get opens for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return Array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-opened-AIM($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-opened-AIM($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : Retrieve the list of email addresses that opened a given campaign with how many times they opened.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignopenedaim.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get opens for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return Array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-opened-AIM($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignOpenedAIM", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-not-opened-AIM-5'>campaign-not-opened-AIM#5</a>.
 :
 : @see <a href='#campaign-not-opened-AIM-5'>campaign-not-opened-AIM#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get no opens for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return Array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-not-opened-AIM($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-not-opened-AIM($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : Retrieve the list of email addresses that did not open a given campaign string email Email address that opened the campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignnotopenedaim.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get no opens for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return array array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-not-opened-AIM($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignNotOpenedAIM", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-click-detail-AIM-6'>campaign-click-detail-AIM#6</a>.
 :
 : @see <a href='#campaign-click-detail-AIM-6'>campaign-click-detail-AIM#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get click stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $url the URL of the link that was clicked on
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return Array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-click-detail-AIM($apikey as xs:string, $cid as xs:string, $url as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-click-detail-AIM($mailchimp:endpoint, $apikey, $cid, $url, $start, $limit)
};

(:~
 : Return the list of email addresses that clicked on a given url, and how many times they clicked.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignclickdetailaim.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get click stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $url the URL of the link that was clicked on
 : @param $start art optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit mit optional for large data sets, the number of results to return - defaults to 1000, upper limit set at 15000
 :
 : @return Array containing the total records matched and the specific records for this page
 :)
declare sequential function mailchimp:campaign-click-detail-AIM($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $url as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignClickDetailAIM", ($apikey, $cid, $url, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-email-stats-AIM-4'>campaign-email-stats-AIM#4</a>.
 :
 : @see <a href='#campaign-email-stats-AIM-4'>campaign-email-stats-AIM#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $email_address an array of up to 50 email addresses to check OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns. For backwards compatibility, if a string is passed, it will be treated as an array with a single element (will not work with XML-RPC).
 :
 : @return Array an array with the keys listed in Returned Fields below
 :)
declare sequential function mailchimp:campaign-email-stats-AIM($apikey as xs:string, $cid as xs:string, $email_address as element(array)){
  mailchimp:campaign-email-stats-AIM($mailchimp:endpoint, $apikey, $cid, $email_address)
};

(:~
 : Given a campaign and email address, return the entire click and open history with timestamps, ordered by time.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignemailstatsaim.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $email_address an array of up to 50 email addresses to check OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns. For backwards compatibility, if a string is passed, it will be treated as an array with a single element (will not work with XML-RPC).
 :
 : @return Array an array with the keys listed in Returned Fields below
 :)
declare sequential function mailchimp:campaign-email-stats-AIM($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $email_address as element(array)){
  xmlrpc:invoke($endpoint-url, "campaignEmailStatsAIM", ($apikey, $cid, $email_address))
};

(:~
 :
 : Convenience function for <a href='#campaign-email-stats-AIM-all-5'>campaign-email-stats-AIM-all#5</a>.
 :
 : @see <a href='#campaign-email-stats-AIM-all-5'>campaign-email-stats-AIM-all#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $cid the campaign id to get stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 1000
 :
 : @return Array containing a total record count and data including the actions (opens and clicks) for each email, with timestamps
 :)
declare sequential function mailchimp:campaign-email-stats-AIM-all($apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:campaign-email-stats-AIM-all($mailchimp:endpoint, $apikey, $cid, $start, $limit)
};

(:~
 : Given a campaign and correct paging limits, return the entire click and open history with timestamps, ordered by time, for every user a campaign was delivered to.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignemailstatsaimall.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $cid the campaign id to get stats for (can be gathered using <a href="#campaigns-4">campaigns()</a>)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 1000
 :
 : @return Array containing a total record count and data including the actions (opens and clicks) for each email, with timestamps
 :)
declare sequential function mailchimp:campaign-email-stats-AIM-all($endpoint-url as xs:string, $apikey as xs:string, $cid as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "campaignEmailStatsAIMAll", ($apikey, $cid, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#campaign-ecomm-order-add-3'>campaign-ecomm-order-add#3</a>.
 :
 : @see <a href='#campaign-ecomm-order-add-3'>campaign-ecomm-order-add#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $order an array of information pertaining to the order that has completed. Use the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaignecommorderadd.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return True if the data is saved, otherwise an error is thrown.
 :)
declare sequential function mailchimp:campaign-ecomm-order-add($apikey as xs:string, $order as element(array)){
  mailchimp:campaign-ecomm-order-add($mailchimp:endpoint, $apikey, $order)
};

(:~
 : Attach Ecommerce Order Information to a Campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignecommorderadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $order an array of information pertaining to the order that has completed. Use the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/campaignecommorderadd.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return True if the data is saved, otherwise an error is thrown.
 :)
declare sequential function mailchimp:campaign-ecomm-order-add($endpoint-url as xs:string, $apikey as xs:string, $order as element(array)){
  xmlrpc:invoke($endpoint-url, "campaignEcommOrderAdd", ($apikey, $order))
};

(:~
 :
 : Convenience function for <a href='#lists-5'>lists#5</a>.
 :
 : @see <a href='#lists-5'>lists#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $filters a hash of filters to apply to this query - all are optional. See <a href='http://apidocs.mailchimp.com/rtfm/lists.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $start optional - control paging of lists, start results at this list #, defaults to 1st page of data (page 0)
 : @param $limit optional - control paging of lists, number of lists to return with each call, defaults to 25 (max=100)
 :
 : @return Array with keys listed in Returned Fields below
 :)
declare sequential function mailchimp:lists($apikey as xs:string, $filters as element(array), $start as xs:integer, $limit as xs:integer){
  mailchimp:lists($mailchimp:endpoint, $apikey, $filters, $start, $limit)
};

(:~
 : Retrieve all of the lists defined for your user account.
 :
 : @see http://apidocs.mailchimp.com/rtfm/lists.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $filters a hash of filters to apply to this query - all are optional. See <a href='http://apidocs.mailchimp.com/rtfm/lists.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $start optional - control paging of lists, start results at this list #, defaults to 1st page of data (page 0)
 : @param $limit optional - control paging of lists, number of lists to return with each call, defaults to 25 (max=100)
 :
 : @return Array with keys listed in Returned Fields below
 :)
declare sequential function mailchimp:lists($endpoint-url as xs:string, $apikey as xs:string, $filters as element(array), $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "lists", ($apikey, $filters, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#list-merge-vars-3'>list-merge-vars#3</a>.
 :
 : @see <a href='#list-merge-vars-3'>list-merge-vars#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of merge tags for the list
 :)
declare sequential function mailchimp:list-merge-vars($apikey as xs:string, $id as xs:string){
  mailchimp:list-merge-vars($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Get the list of merge tags for a given list, including their name, tag, and required setting.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmergevars.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of merge tags for the list
 :)
declare sequential function mailchimp:list-merge-vars($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listMergeVars", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-merge-var-add-6'>list-merge-var-add#6</a>.
 :
 : @see <a href='#list-merge-var-add-6'>list-merge-var-add#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to add, e.g. FNAME
 : @param $name The long description of the tag being added, used for user displays
 : @param $options optional Various options for this merge var. <em>note:</em> for historical purposes this can also take a "boolean"
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-add($apikey as xs:string, $id as xs:string, $tag as xs:string, $name as xs:string, $options as element(array)){
  mailchimp:list-merge-var-add($mailchimp:endpoint, $apikey, $id, $tag, $name, $options)
};

(:~
 : Add a new merge tag to a given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmergevaradd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to add, e.g. FNAME
 : @param $name The long description of the tag being added, used for user displays
 : @param $options optional Various options for this merge var. <em>note:</em> for historical purposes this can also take a "boolean"
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $tag as xs:string, $name as xs:string, $options as element(array)){
  xmlrpc:invoke($endpoint-url, "listMergeVarAdd", ($apikey, $id, $tag, $name, $options))
};

(:~
 :
 : Convenience function for <a href='#list-merge-var-update-5'>list-merge-var-update#5</a>.
 :
 : @see <a href='#list-merge-var-update-5'>list-merge-var-update#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to update
 : @param $options The options to change for a merge var. See <a href="#list-merge-var-add-5">list-merge-var-add()</a> for valid options
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-update($apikey as xs:string, $id as xs:string, $tag as xs:string, $options as element(array)){
  mailchimp:list-merge-var-update($mailchimp:endpoint, $apikey, $id, $tag, $options)
};

(:~
 : Update most parameters for a merge tag on a given list. You cannot currently change the merge type.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmergevarupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to update
 : @param $options The options to change for a merge var. See <a href="#list-merge-var-add-5">list-merge-var-add()</a> for valid options
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-update($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $tag as xs:string, $options as element(array)){
  xmlrpc:invoke($endpoint-url, "listMergeVarUpdate", ($apikey, $id, $tag, $options))
};

(:~
 :
 : Convenience function for <a href='#list-merge-var-del-4'>list-merge-var-del#4</a>.
 :
 : @see <a href='#list-merge-var-del-4'>list-merge-var-del#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to delete
 :
 : @return bool true if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-del($apikey as xs:string, $id as xs:string, $tag as xs:string){
  mailchimp:list-merge-var-del($mailchimp:endpoint, $apikey, $id, $tag)
};

(:~
 : Delete a merge tag from a given list and all its members. Seriously - the data is removed from all members as well! Note that on large lists this method may seem a bit slower than calls you typically make.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmergevardel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $tag The merge tag to delete
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-merge-var-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $tag as xs:string){
  xmlrpc:invoke($endpoint-url, "listMergeVarDel", ($apikey, $id, $tag))
};

(:~
 :
 : Convenience function for <a href='#list-interest-groupings-3'>list-interest-groupings#3</a>.
 :
 : @see <a href='#list-interest-groupings-3'>list-interest-groupings#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of interest groups for the list
 :)
declare sequential function mailchimp:list-interest-groupings($apikey as xs:string, $id as xs:string){
  mailchimp:list-interest-groupings($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Get the list of interest groupings for a given list, including the label, form information, and included groups for each.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupings.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of interest groups for the list
 :)
declare sequential function mailchimp:list-interest-groupings($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listInterestGroupings", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-interest-group-add-5'>list-interest-group-add#5</a>.
 :
 : @see <a href='#list-interest-group-add-5'>list-interest-group-add#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $group_name the interest group to add - group names must be unique within a grouping
 : @param $grouping_id ouping_id The grouping to add the new group to - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a>. If not supplied, the first grouping on the list is used.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-add($apikey as xs:string, $id as xs:string, $group_name as xs:string, $grouping_id as xs:integer){
  mailchimp:list-interest-group-add($mailchimp:endpoint, $apikey, $id, $group_name, $grouping_id)
};

(:~
 : Add a single Interest Group - if interest groups for the List are not yet enabled, adding the first group will automatically turn them on.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $group_name the interest group to add - group names must be unique within a grouping
 : @param $grouping_id ouping_id The grouping to add the new group to - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a> . If not supplied, the first grouping on the list is used.
 :
 : @return bool true if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $group_name as xs:string, $grouping_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listInterestGroupAdd", ($apikey, $id, $group_name, $grouping_id))
};

(:~
 :
 : Convenience function for <a href='#list-interest-group-del-5'>list-interest-group-del#5</a>.
 :
 : @see <a href='#list-interest-group-del-5'>list-interest-group-del#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $group_name the interest group to delete
 : @param $grouping_id The grouping to delete the group from - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a> . If not supplied, the first grouping on the list is used.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-del($apikey as xs:string, $id as xs:string, $group_name as xs:string, $grouping_id as xs:integer){
  mailchimp:list-interest-group-del($mailchimp:endpoint, $apikey, $id, $group_name, $grouping_id)
};

(:~
 : Delete a single Interest Group - if the last group for a list is deleted, this will also turn groups for the list off.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $group_name the interest group to delete
 : @param $grouping_id The grouping to delete the group from - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a> . If not supplied, the first grouping on the list is used.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $group_name as xs:string, $grouping_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listInterestGroupDel", ($apikey, $id, $group_name, $grouping_id))
};

(:~
 :
 : Convenience function for <a href='#list-interest-group-update-6'>list-interest-group-update#6</a>.
 :
 : @see <a href='#list-interest-group-update-6'>list-interest-group-update#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $old_name the interest group name to be changed
 : @param $new_name the new interest group name to be set
 : @param $grouping_id ouping_id The grouping to delete the group from - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a> . If not supplied, the first grouping on the list is used.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-update($apikey as xs:string, $id as xs:string, $old_name as xs:string, $new_name as xs:string, $grouping_id as xs:integer){
  mailchimp:list-interest-group-update($mailchimp:endpoint, $apikey, $id, $old_name, $new_name, $grouping_id)
};

(:~
 : Change the name of an Interest Group.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $old_name the interest group name to be changed
 : @param $new_name the new interest group name to be set
 : @param $grouping_id ouping_id The grouping to delete the group from - get using <a href="#list-interest-groupings-2">list-interest-groupings()</a> . If not supplied, the first grouping on the list is used.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-group-update($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $old_name as xs:string, $new_name as xs:string, $grouping_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listInterestGroupUpdate", ($apikey, $id, $old_name, $new_name, $grouping_id))
};

(:~
 :
 : Convenience function for <a href='#list-interest-grouping-add-6'>list-interest-grouping-add#6</a>.
 :
 : @see <a href='#list-interest-grouping-add-6'>list-interest-grouping-add#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $name the interest grouping to add - grouping names must be unique
 : @param $type The type of the grouping to add - one of "checkboxes", "hidden", "dropdown", "radio"
 : @param $groups The lists of initial group names to be added - at least 1 is required and the names must be unique within a grouping. If the number takes you over the 60 group limit, an error will be thrown.
 :
 : @return The new grouping id if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-add($apikey as xs:string, $id as xs:string, $name as xs:string, $type as xs:string, $groups as element(array)){
  mailchimp:list-interest-grouping-add($mailchimp:endpoint, $apikey, $id, $name, $type, $groups)
};

(:~
 : Add a new Interest Grouping - if interest groups for the List are not yet enabled, adding the first grouping will automatically turn them on.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupingadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $name the interest grouping to add - grouping names must be unique
 : @param $type The type of the grouping to add - one of "checkboxes", "hidden", "dropdown", "radio"
 : @param $groups The lists of initial group names to be added - at least 1 is required and the names must be unique within a grouping. If the number takes you over the 60 group limit, an error will be thrown.
 :
 : @return The new grouping id if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $name as xs:string, $type as xs:string, $groups as element(array)){
  xmlrpc:invoke($endpoint-url, "listInterestGroupingAdd", ($apikey, $id, $name, $type, $groups))
};

(:~
 :
 : Convenience function for <a href='#list-interest-grouping-update-5'>list-interest-grouping-update#5</a>.
 :
 : @see <a href='#list-interest-grouping-update-5'>list-interest-grouping-update#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $grouping_id the interest grouping id - get from <a href="#list-interest-groupings-2">list-interest-groupings()</a>
 : @param $name The name of the field to update - either "name" or "type". Groups with in the grouping should be manipulated using the standard listInterestGroup* methods
 : @param $value The new value of the field. Grouping names must be unique - only "hidden" and "checkboxes" grouping types can be converted between each other.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-update($apikey as xs:string, $grouping_id as xs:integer, $name as xs:string, $value as xs:string){
  mailchimp:list-interest-grouping-update($mailchimp:endpoint, $apikey, $grouping_id, $name, $value)
};

(:~
 : Update an existing Interest Grouping.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupingupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $grouping_id the interest grouping id - get from <a href="#list-interest-groupings-2">list-interest-groupings()</a>
 : @param $name The name of the field to update - either "name" or "type". Groups with in the grouping should be manipulated using the standard listInterestGroup* methods
 : @param $value The new value of the field. Grouping names must be unique - only "hidden" and "checkboxes" grouping types can be converted between each other.
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-update($endpoint-url as xs:string, $apikey as xs:string, $grouping_id as xs:integer, $name as xs:string, $value as xs:string){
  xmlrpc:invoke($endpoint-url, "listInterestGroupingUpdate", ($apikey, $grouping_id, $name, $value))
};

(:~
 :
 : Convenience function for <a href='#list-interest-grouping-del-3'>list-interest-grouping-del#3</a>.
 :
 : @see <a href='#list-interest-grouping-del-3'>list-interest-grouping-del#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $grouping_id the interest grouping id - get from <a href="#list-interest-groupings-2">list-interest-groupings()</a>
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-del($apikey as xs:string, $grouping_id as xs:integer){
  mailchimp:list-interest-grouping-del($mailchimp:endpoint, $apikey, $grouping_id)
};

(:~
 : Delete an existing Interest Grouping - this will permanently delete all contained interest groups and will remove those selections from all list members.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listinterestgroupingdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $grouping_id the interest grouping id - get from <a href="#list-interest-groupings-2">list-interest-groupings()</a>
 :
 : @return True if the request succeeds, otherwise an error will be thrown
 :)
declare sequential function mailchimp:list-interest-grouping-del($endpoint-url as xs:string, $apikey as xs:string, $grouping_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listInterestGroupingDel", ($apikey, $grouping_id))
};

(:~
 :
 : Convenience function for <a href='#list-webhooks-3'>list-webhooks#3</a>.
 :
 : @see <a href='#list-webhooks-3'>list-webhooks#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of webhooks
 :)
declare sequential function mailchimp:list-webhooks($apikey as xs:string, $id as xs:string){
  mailchimp:list-webhooks($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Return the Webhooks configured for the given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listwebhooks.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return List of webhooks
 :)
declare sequential function mailchimp:list-webhooks($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listWebhooks", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-webhook-add-6'>list-webhook-add#6</a>.
 :
 : @see <a href='#list-webhook-add-6'>list-webhook-add#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $url a valid URL for the Webhook - it will be validated. note that a url may only exist on a list once.
 : @param $actions optional a hash of actions to fire this Webhook for
 : @param $sources optional a hash of sources to fire this Webhook for
 :
 : @return True if the call succeeds, otherwise an exception will be thrown
 :)
declare sequential function mailchimp:list-webhook-add($apikey as xs:string, $id as xs:string, $url as xs:string, $actions as element(array), $sources as element(array)){
  mailchimp:list-webhook-add($mailchimp:endpoint, $apikey, $id, $url, $actions, $sources)
};

(:~
 : Add a new Webhook URL for the given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listwebhookadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $url a valid URL for the Webhook - it will be validated. note that a url may only exist on a list once.
 : @param $actions optional a hash of actions to fire this Webhook for
 : @param $sources optional a hash of sources to fire this Webhook for
 :
 : @return True if the call succeeds, otherwise an exception will be thrown
 :)
declare sequential function mailchimp:list-webhook-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $url as xs:string, $actions as element(array), $sources as element(array)){
  xmlrpc:invoke($endpoint-url, "listWebhookAdd", ($apikey, $id, $url, $actions, $sources))
};

(:~
 :
 : Convenience function for <a href='#list-webhook-del-4'>list-webhook-del#4</a>.
 :
 : @see <a href='#list-webhook-del-4'>list-webhook-del#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $url the URL of a Webhook on this list
 :
 : @return True if the call succeeds, otherwise an exception will be thrown
 :)
declare sequential function mailchimp:list-webhook-del($apikey as xs:string, $id as xs:string, $url as xs:string){
  mailchimp:list-webhook-del($mailchimp:endpoint, $apikey, $id, $url)
};

(:~
 : Delete an existing Webhook URL from a given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listwebhookdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $url the URL of a Webhook on this list
 :
 : @return True if the call succeeds, otherwise an exception will be thrown
 :)
declare sequential function mailchimp:list-webhook-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $url as xs:string){
  xmlrpc:invoke($endpoint-url, "listWebhookDel", ($apikey, $id, $url))
};

(:~
 :
 : Convenience function for <a href='#list-static-segments-3'>list-static-segments#3</a>.
 :
 : @see <a href='#list-static-segments-3'>list-static-segments#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return An array of parameters for each static segment
 :)
declare sequential function mailchimp:list-static-segments($apikey as xs:string, $id as xs:string){
  mailchimp:list-static-segments($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Retrieve all of the Static Segments for a list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegments.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return An array of parameters for each static segment
 :)
declare sequential function mailchimp:list-static-segments($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listStaticSegments", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-static-segment-add-4'>list-static-segment-add#4</a>.
 :
 : @see <a href='#list-static-segment-add-4'>list-static-segment-add#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $name a unique name per list for the segment - 50 byte maximum length, anything longer will throw an error
 :
 : @return The id of the new segment, otherwise an error will be thrown.
 :)
declare sequential function mailchimp:list-static-segment-add($apikey as xs:string, $id as xs:string, $name as xs:string){
  mailchimp:list-static-segment-add($mailchimp:endpoint, $apikey, $id, $name)
};

(:~
 : Save a segment against a list for later use. There is no limit to the number of segments which can be saved. Static Segments <strong>are not</strong> tied to any merge data, interest groups, etc. They essentially allow you to configure an unlimited number of custom segments which will have standard performance. When using proper segments, Static Segments are one of the available options for segmentation just as if you used a merge var (and they can be used with other segmentation options), though performance may degrade at that point.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegmentadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $name a unique name per list for the segment - 50 byte maximum length, anything longer will throw an error
 :
 : @return The id of the new segment, otherwise an error will be thrown.
 :)
declare sequential function mailchimp:list-static-segment-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $name as xs:string){
  xmlrpc:invoke($endpoint-url, "listStaticSegmentAdd", ($apikey, $id, $name))
};

(:~
 :
 : Convenience function for <a href='#list-static-segment-reset-4'>list-static-segment-reset#4</a>.
 :
 : @see <a href='#list-static-segment-reset-4'>list-static-segment-reset#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to reset - get from <a href="#list-static-segments-2">list-static-segments()</a>
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:list-static-segment-reset($apikey as xs:string, $id as xs:string, $seg_id as xs:integer){
  mailchimp:list-static-segment-reset($mailchimp:endpoint, $apikey, $id, $seg_id)
};

(:~
 : Resets a static segment - removes <strong>all</strong> members from the static segment. Note: does not actually affect list member data.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegmentreset.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to reset - get from <a href="#list-static-segments-2">list-static-segments()</a>
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:list-static-segment-reset($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $seg_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listStaticSegmentReset", ($apikey, $id, $seg_id))
};

(:~
 :
 : Convenience function for <a href='#listStaticSegmentDel-4'>list-static-segment-del#4</a>.
 :
 : @see <a href='#list-static-segment-del-4'>list-static-segment-del#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to delete - get from <a href="#list-static-segments-2">list-static-segments()</a>
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:list-static-segment-del($apikey as xs:string, $id as xs:string, $seg_id as xs:integer){
  mailchimp:list-static-segment-del($mailchimp:endpoint, $apikey, $id, $seg_id)
};

(:~
 : Delete a static segment. Note that this will, of course, remove any member affiliations with the segment.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegmentdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to delete - get from <a href="#list-static-segments-2">list-static-segments()</a>
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:list-static-segment-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $seg_id as xs:integer){
  xmlrpc:invoke($endpoint-url, "listStaticSegmentDel", ($apikey, $id, $seg_id))
};

(:~
 :
 : Convenience function for <a href='#list-static-segment-members-add-5'>list-static-segment-members-add#5</a>.
 :
 : @see <a href='#list-static-segment-members-add-5'>list-static-segment-members-add#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to modify - get from <a href="#list-static-segments-2">list-static-segments()</a>
 : @param $batch an array of email addresses and/or unique_ids to add to the segment
 :
 : @return An array with the results of the operation
 :)
declare sequential function mailchimp:list-static-segment-members-add($apikey as xs:string, $id as xs:string, $seg_id as xs:integer, $batch as element(array)){
  mailchimp:list-static-segment-members-add($mailchimp:endpoint, $apikey, $id, $seg_id, $batch)
};

(:~
 : Add list members to a static segment. It is suggested that you limit batch size to no more than 10,000 addresses per call. Email addresses must exist on the list in order to be included - this <strong>will not</strong> subscribe them to the list!.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegmentmembersadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to modify - get from <a href="#list-static-segments-2">list-static-segments()</a>
 : @param $batch an array of email addresses and/or unique_ids to add to the segment
 :
 : @return array an array with the results of the operation
 :)
declare sequential function mailchimp:list-static-segment-members-add($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $seg_id as xs:integer, $batch as element(array)){
  xmlrpc:invoke($endpoint-url, "listStaticSegmentMembersAdd", ($apikey, $id, $seg_id, $batch))
};

(:~
 :
 : Convenience function for <a href='#list-static-segment-members-del-5'>list-static-segment-members-del#5</a>.
 :
 : @see <a href='#list-static-segment-members-del-5'>list-static-segment-members-del#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to delete - get from <a href="#list-static-segments-2">list-static-segments()</a>
 : @param $batch an array of email addresses and/or unique_ids to remove from the segment
 :
 : @return An array with the results of the operation
 :)
declare sequential function mailchimp:list-static-segment-members-del($apikey as xs:string, $id as xs:string, $seg_id as xs:integer, $batch as element(array)){
  mailchimp:list-static-segment-members-del($mailchimp:endpoint, $apikey, $id, $seg_id, $batch)
};

(:~
 : Remove list members from a static segment. It is suggested that you limit batch size to no more than 10,000 addresses per call. Email addresses must exist on the list in order to be removed - this <strong>will not</strong> unsubscribe them from the list!.
 :
 : @see http://apidocs.mailchimp.com/rtfm/liststaticsegmentmembersdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $seg_id the id of the static segment to delete - get from <a href="#list-static-segments-2">list-static-segments()</a>
 : @param $batch an array of email addresses and/or unique_ids to remove from the segment
 :
 : @return An array with the results of the operation
 :)
declare sequential function mailchimp:list-static-segment-members-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $seg_id as xs:integer, $batch as element(array)){
  xmlrpc:invoke($endpoint-url, "listStaticSegmentMembersDel", ($apikey, $id, $seg_id, $batch))
};

(:~
 :
 : Convenience function for <a href="#list-subscribe-10">list-subscribe#10</a>.
 :
 : @see <a href="#list-subscribe-10">list-subscribe#10</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the email address to subscribe
 : @param $merge_vars optional merges for the email (FNAME, LNAME, etc.) (see examples below for handling "blank" arrays). Note that a merge field can only hold up to 255 bytes. Also, there are a few "special" keys. See <a href='http://apidocs.mailchimp.com/rtfm/listsubscribe.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $email_type optional email type preference for the email (html, text, or mobile defaults to html)
 : @param $double_optin optional flag to control whether a double opt-in confirmation message is sent, defaults to true. <em>Abusing this may cause your account to be suspended.</em>
 : @param $update_existing optional flag to control whether a existing subscribers should be updated instead of throwing and error, defaults to false
 : @param $replace_interests optional flag to determine whether we replace the interest groups with the groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 : @param $send_welcome optional if your double_optin is false and this is true, we will send your lists Welcome Email if this subscribe succeeds - this will *not* fire if we end up updating an existing subscriber. If double_optin is true, this has no effect. defaults to false.
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-subscribe($apikey as xs:string, $id as xs:string, $email_address as xs:string, $merge_vars as element(array), $email_type as xs:string, $double_optin as xs:boolean, $update_existing as xs:boolean, $replace_interests as xs:boolean, $send_welcome as xs:boolean){
  mailchimp:list-subscribe($mailchimp:endpoint, $apikey, $id, $email_address, $merge_vars, $email_type, $double_optin, $update_existing, $replace_interests, $send_welcome)
};

(:~
 : Subscribe the provided email to a list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listsubscribe.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the email address to subscribe
 : @param $merge_vars optional merges for the email (FNAME, LNAME, etc.) (see examples below for handling "blank" arrays). Note that a merge field can only hold up to 255 bytes. Also, there are a few "special" keys. See <a href='http://apidocs.mailchimp.com/rtfm/listsubscribe.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 : @param $email_type optional email type preference for the email (html, text, or mobile defaults to html)
 : @param $double_optin optional flag to control whether a double opt-in confirmation message is sent, defaults to true. <em>Abusing this may cause your account to be suspended.</em>
 : @param $update_existing optional flag to control whether a existing subscribers should be updated instead of throwing and error, defaults to false
 : @param $replace_interests optional flag to determine whether we replace the interest groups with the groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 : @param $send_welcome optional if your double_optin is false and this is true, we will send your lists Welcome Email if this subscribe succeeds - this will *not* fire if we end up updating an existing subscriber. If double_optin is true, this has no effect. defaults to false.
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-subscribe($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $email_address as xs:string, $merge_vars as element(array), $email_type as xs:string, $double_optin as xs:boolean, $update_existing as xs:boolean, $replace_interests as xs:boolean, $send_welcome as xs:boolean){
  xmlrpc:invoke($endpoint-url, "listSubscribe", ($apikey, $id, $email_address, $merge_vars, $email_type, $double_optin, $update_existing, $replace_interests, $send_welcome))
};

(:~
 :
 : Convenience function for <a href='#list-unsubscribe-7'>list-unsubscribe#7</a>.
 :
 : @see <a href='#list-unsubscribe-7'>list-unsubscribe#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the email address to unsubscribe OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 : @param $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
 : @param $send_goodbye flag to send the goodbye email to the email address, defaults to true
 : @param $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to true
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-unsubscribe($apikey as xs:string, $id as xs:string, $email_address as xs:string, $delete_member as xs:boolean, $send_goodbye as xs:boolean, $send_notify as xs:boolean){
  mailchimp:list-unsubscribe($mailchimp:endpoint, $apikey, $id, $email_address, $delete_member, $send_goodbye, $send_notify)
};

(:~
 : Unsubscribe the given email address from the list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listunsubscribe.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the email address to unsubscribe OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 : @param $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
 : @param $send_goodbye flag to send the goodbye email to the email address, defaults to true
 : @param $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to true
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-unsubscribe($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $email_address as xs:string, $delete_member as xs:boolean, $send_goodbye as xs:boolean, $send_notify as xs:boolean){
  xmlrpc:invoke($endpoint-url, "listUnsubscribe", ($apikey, $id, $email_address, $delete_member, $send_goodbye, $send_notify))
};

(:~
 :
 : Convenience function for <a href='#list-update-member-7'>list-update-member#7</a>.
 :
 : @see <a href='#list-update-member-7'>list-update-member#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the current email address of the member to update OR the "id" for the member returned from listMemberInfo, Webhooks, and Campaigns
 : @param $merge_vars array of new field values to update the member with. See merge_vars in <a href="#list-subscribe-10">list-subscribe()</a> for details.
 : @param $email_type change the email type preference for the member ("html", "text", or "mobile"). Leave blank to keep the existing preference (optional)
 : @param $replace_interests flag to determine whether we replace the interest groups with the updated groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-update-member($apikey as xs:string, $id as xs:string, $email_address as xs:string, $merge_vars as element(array), $email_type as xs:string, $replace_interests as xs:boolean){
  mailchimp:list-update-member($mailchimp:endpoint, $apikey, $id, $email_address, $merge_vars, $email_type, $replace_interests)
};

(:~
 : Edit the email address, merge fields, and interest groups for a list member. If you are doing a batch update on lots of users, consider using <a href="#list-batch-subscribe-6">#list-batch-subscribe()</a> with the update_existing and possible replace_interests parameter.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listupdatemember.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address the current email address of the member to update OR the "id" for the member returned from listMemberInfo, Webhooks, and Campaigns
 : @param $merge_vars array of new field values to update the member with. See merge_vars in <a href="#list-subscribe-10">list-subscribe()</a> for details.
 : @param $email_type change the email type preference for the member ("html", "text", or "mobile"). Leave blank to keep the existing preference (optional)
 : @param $replace_interests flag to determine whether we replace the interest groups with the updated groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 :
 : @return True on success, false on failure.
 :)
declare sequential function mailchimp:list-update-member($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $email_address as xs:string, $merge_vars as element(array), $email_type as xs:string, $replace_interests as xs:boolean){
  xmlrpc:invoke($endpoint-url, "listUpdateMember", ($apikey, $id, $email_address, $merge_vars, $email_type, $replace_interests))
};

(:~
 :
 : Convenience function for <a href='#list-batch-subscribe-7'>list-batch-subscribe#7</a>.
 :
 : @see <a href='#list-batch-subscribe-7'>list-batch-subscribe#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $batch an array of structs for each address to import with two special keys: "EMAIL" for the email address, and "EMAIL_TYPE" for the email type option (html, text, or mobile)
 : @param $double_optin flag to control whether to send an opt-in confirmation email - defaults to true
 : @param $update_existing flag to control whether to update members that are already subscribed to the list or to return an error, defaults to false (return error)
 : @param $replace_interests flag to determine whether we replace the interest groups with the updated groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 :
 : @return Array of result counts and any errors that occurred
 :)
declare sequential function mailchimp:list-batch-subscribe($apikey as xs:string, $id as xs:string, $batch as element(array), $double_optin as xs:boolean, $update_existing as xs:boolean, $replace_interests as xs:boolean){
  mailchimp:list-batch-subscribe($mailchimp:endpoint, $apikey, $id, $batch, $double_optin, $update_existing, $replace_interests)
};

(:~
 : Subscribe a batch of email addresses to a list at once. If you are using a serialized version of the API, we strongly suggest that you only run this method as a POST request, and <em>not</em> a GET request. Maximum batch sizes vary based on the amount of data in each record, though you should cap them at 5k - 10k records, depending on your experience. These calls are also long, so be sure you increase your timeout values.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listbatchsubscribe.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $batch an array of structs for each address to import with two special keys: "EMAIL" for the email address, and "EMAIL_TYPE" for the email type option (html, text, or mobile)
 : @param $double_optin flag to control whether to send an opt-in confirmation email - defaults to true
 : @param $update_existing flag to control whether to update members that are already subscribed to the list or to return an error, defaults to false (return error)
 : @param $replace_interests flag to determine whether we replace the interest groups with the updated groups provided, or we add the provided groups to the member's interest groups (optional, defaults to true)
 :
 : @return Array of result counts and any errors that occurred
 :)
declare sequential function mailchimp:list-batch-subscribe($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $batch as element(array), $double_optin as xs:boolean, $update_existing as xs:boolean, $replace_interests as xs:boolean){
  xmlrpc:invoke($endpoint-url, "listBatchSubscribe", ($apikey, $id, $batch, $double_optin, $update_existing, $replace_interests))
};

(:~
 :
 : Convenience function for <a href='#list-batch-unsubscribe-7'>list-batch-unsubscribe#7</a>.
 :
 : @see <a href='#list-batch-unsubscribe-7'>list-batch-unsubscribe#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $emails array of email addresses to unsubscribe
 : @param $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
 : @param $send_goodbye flag to send the goodbye email to the email addresses, defaults to true
 : @param $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to false
 :
 : @return Array of result counts and any errors that occurred
 :)
declare sequential function mailchimp:list-batch-unsubscribe($apikey as xs:string, $id as xs:string, $emails as element(array), $delete_member as xs:boolean, $send_goodbye as xs:boolean, $send_notify as xs:boolean){
  mailchimp:list-batch-unsubscribe($mailchimp:endpoint, $apikey, $id, $emails, $delete_member, $send_goodbye, $send_notify)
};

(:~
 : Unsubscribe a batch of email addresses to a list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listbatchunsubscribe.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $emails array of email addresses to unsubscribe
 : @param $delete_member flag to completely delete the member from your list instead of just unsubscribing, default to false
 : @param $send_goodbye flag to send the goodbye email to the email addresses, defaults to true
 : @param $send_notify flag to send the unsubscribe notification email to the address defined in the list email notification settings, defaults to false
 :
 : @return Array of result counts and any errors that occurred
 :)
declare sequential function mailchimp:list-batch-unsubscribe($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $emails as element(array), $delete_member as xs:boolean, $send_goodbye as xs:boolean, $send_notify as xs:boolean){
  xmlrpc:invoke($endpoint-url, "listBatchUnsubscribe", ($apikey, $id, $emails, $delete_member, $send_goodbye, $send_notify))
};

(:~
 :
 : Convenience function for <a href='#list-members-7'>list-members#7</a>.
 :
 : @see <a href='#list-members-7'>list-members#7</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $status the status to get members for - one of(subscribed, unsubscribed, <a target="_blank" href="http://eepurl.com/dwk1">cleaned</a>, updated), defaults to subscribed
 : @param $since optional pull all members whose status (subscribed/unsubscribed/cleaned) has changed or whose profile (updated) has changed since this date/time (in GMT) - format is YYYY-MM-DD HH:mm:ss (24hr)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 15000
 :
 : @return Array of a the total records match and matching list member data for this page (see Returned Fields for details)
 :)
declare sequential function mailchimp:list-members($apikey as xs:string, $id as xs:string, $status as xs:string, $since as xs:string, $start as xs:integer, $limit as xs:integer){
  mailchimp:list-members($mailchimp:endpoint, $apikey, $id, $status, $since, $start, $limit)
};

(:~
 : Get all of the list members for a list that are of a particular status.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmembers.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $status the status to get members for - one of(subscribed, unsubscribed, <a target="_blank" href="http://eepurl.com/dwk1">cleaned</a>, updated), defaults to subscribed
 : @param $since optional pull all members whose status (subscribed/unsubscribed/cleaned) has changed or whose profile (updated) has changed since this date/time (in GMT) - format is YYYY-MM-DD HH:mm:ss (24hr)
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 15000
 :
 : @return Array of a the total records match and matching list member data for this page (see Returned Fields for details)
 :)
declare sequential function mailchimp:list-members($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $status as xs:string, $since as xs:string, $start as xs:integer, $limit as xs:integer){
  xmlrpc:invoke($endpoint-url, "listMembers", ($apikey, $id, $status, $since, $start, $limit))
};

(:~
 :
 : Convenience function for <a href='#list-member-info-4'>list-member-info#4</a>.
 :
 : @see <a href='#list-member-info-4'>list-member-info#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address an array of up to 50 email addresses to get information for OR the "id"(s) for the member returned from listMembers, Webhooks, and Campaigns. For backwards compatibility, if a string is passed, it will be treated as an array with a single element (will not work with XML-RPC).
 :
 : @return Array of list members with their info in an array (see Returned Fields for details)
 :)
declare sequential function mailchimp:list-member-info($apikey as xs:string, $id as xs:string, $email_address as element(array)){
  mailchimp:list-member-info($mailchimp:endpoint, $apikey, $id, $email_address)
};

(:~
 : Get all the information for particular members of a list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmemberinfo.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address an array of up to 50 email addresses to get information for OR the "id"(s) for the member returned from listMembers, Webhooks, and Campaigns. For backwards compatibility, if a string is passed, it will be treated as an array with a single element (will not work with XML-RPC).
 :
 : @return Array of list members with their info in an array (see Returned Fields for details)
 :)
declare sequential function mailchimp:list-member-info($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $email_address as element(array)){
  xmlrpc:invoke($endpoint-url, "listMemberInfo", ($apikey, $id, $email_address))
};

(:~
 :
 : Convenience function for <a href='#list-member-activity-4'>list-member-activity#4</a>.
 :
 : @see <a href='#list-member-activity-4'>list-member-activity#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address an array of up to 50 email addresses to get information for OR the "id"(s) for the member returned from listMembers, Webhooks, and Campaigns.
 :
 : @return Array of data and success/error counts
 :)
declare sequential function mailchimp:list-member-activity($apikey as xs:string, $id as xs:string, $email_address as element(array)){
  mailchimp:list-member-activity($mailchimp:endpoint, $apikey, $id, $email_address)
};

(:~
 : Get the most recent 100 activities for particular list members (open, click, bounce, unsub, abuse, sent to).
 :
 : @see http://apidocs.mailchimp.com/rtfm/listmemberactivity.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 : @param $email_address an array of up to 50 email addresses to get information for OR the "id"(s) for the member returned from listMembers, Webhooks, and Campaigns.
 :
 : @return Array of data and success/error counts
 :)
declare sequential function mailchimp:list-member-activity($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $email_address as element(array)){
  xmlrpc:invoke($endpoint-url, "listMemberActivity", ($apikey, $id, $email_address))
};

(:~
 :
 : Convenience function for <a href='#list-abuse-reports-6'>list-abuse-reports#6</a>.
 :
 : @see <a href='#list-abuse-reports-6'>list-abuse-reports#6</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to pull abuse reports for (can be gathered using lists())
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 500, upper limit set at 1000
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return The total of all reports and the specific reports reports this page
 :)
declare sequential function mailchimp:list-abuse-reports($apikey as xs:string, $id as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  mailchimp:list-abuse-reports($mailchimp:endpoint, $apikey, $id, $start, $limit, $since)
};

(:~
 : Get all email addresses that complained about a given campaign.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listabusereports.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to pull abuse reports for (can be gathered using lists())
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 500, upper limit set at 1000
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return The total of all reports and the specific reports reports this page
 :)
declare sequential function mailchimp:list-abuse-reports($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  xmlrpc:invoke($endpoint-url, "listAbuseReports", ($apikey, $id, $start, $limit, $since))
};

(:~
 :
 : Convenience function for <a href='#list-growth-history-3'>list-growth-history#3</a>.
 :
 : @see <a href='#list-growth-history-3'>list-growth-history#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array of months and growth
 :)
declare sequential function mailchimp:list-growth-history($apikey as xs:string, $id as xs:string){
  mailchimp:list-growth-history($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Access the Growth History by Month for a given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listgrowthhistory.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array of months and growth
 :)
declare sequential function mailchimp:list-growth-history($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listGrowthHistory", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-activity-3'>list-activity#3</a>.
 :
 : @see <a href='#list-activity-3'>list-activity#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array of array of daily values.
 :)
declare sequential function mailchimp:list-activity($apikey as xs:string, $id as xs:string){
  mailchimp:list-activity($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Access up to the previous 180 days of daily detailed aggregated activity stats for a given list.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listactivity.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return array array of array of daily values.
 :)
declare sequential function mailchimp:list-activity($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listActivity", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-locations-3'>list-locations#3</a>.
 :
 : @see <a href='#list-locations-3'>list-locations#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array of locations
 :)
declare sequential function mailchimp:list-locations($apikey as xs:string, $id as xs:string){
  mailchimp:list-locations($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Retrieve the locations (countries) that the list's subscribers have been tagged to based on geocoding their IP address.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listlocations.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array of locations
 :)
declare sequential function mailchimp:list-locations($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listLocations", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#list-clients-3'>list-clients#3</a>.
 :
 : @see <a href='#list-clients-3'>list-clients#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return array the desktop and mobile user agents in use on the list
 :)
declare sequential function mailchimp:list-clients($apikey as xs:string, $id as xs:string){
  mailchimp:list-clients($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Retrieve the clients that the list's subscribers have been tagged as being used based on user agents seen. Made possible by <a href="http://user-agent-string.info" target="_blank">user-agent-string.info</a> double penetration the percent of desktop clients in use array clients a record containing the 'client', an 'icon' image url, the 'percent' using the client, and the total 'members' represented double penetration the percent of mobile clients in use array clients a record containing the 'client', an 'icon' image url, the 'percent' using the client, and the total 'members' represented.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listclients.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the list id to connect to. Get by calling <a href="#lists-4">lists()</a>
 :
 : @return Array the desktop and mobile user agents in use on the list
 :)
declare sequential function mailchimp:list-clients($endpoint-url as xs:string, $apikey as xs:string, $id as xs:string){
  xmlrpc:invoke($endpoint-url, "listClients", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#templates-5'>templates#5</a>.
 :
 : @see <a href='#templates-5'>templates#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $types optional the types of templates to return
 : @param $category optional for Gallery templates only, limit to a specific template category
 : @param $inactives optional options to control how inactive templates are returned, if at all
 :
 : @return An array of structs, one for each template (see Returned Fields for details)
 :)
declare sequential function mailchimp:templates($apikey as xs:string, $types as element(array), $category as xs:string, $inactives as element(array)){
  mailchimp:templates($mailchimp:endpoint, $apikey, $types, $category, $inactives)
};

(:~
 : Retrieve various templates available in the system, allowing some thing similar to our template gallery to be created. boolean user Customer template for this user account. Defaults to true. boolean gallery Templates from our Gallery. Note that some templates that require extra configuration are withheld. (eg, the Etsy template). Defaults to false. boolean base Our "start from scratch" extremely basic templates boolean include user templates are not deleted, only set inactive. defaults to false. boolean only only include inactive templates. defaults to false.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templates.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $types optional the types of templates to return
 : @param $category optional for Gallery templates only, limit to a specific template category
 : @param $inactives optional options to control how inactive templates are returned, if at all
 :
 : @return An array of structs, one for each template (see Returned Fields for details)
 :)
declare sequential function mailchimp:templates($endpoint-url as xs:string, $apikey as xs:string, $types as element(array), $category as xs:string, $inactives as element(array)){
  xmlrpc:invoke($endpoint-url, "templates", ($apikey, $types, $category, $inactives))
};

(:~
 :
 : Convenience function for <a href='#template-info-4'>template-info#4</a>.
 :
 : @see <a href='#template-info-4'>template-info#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $tid the template id - get from templates()
 : @param $type the template type to load - one of 'user', 'gallery', 'base'
 :
 : @return An array of info to be used when editing
 :)
declare sequential function mailchimp:template-info($apikey as xs:string, $tid as xs:integer, $type as xs:string){
  mailchimp:template-info($mailchimp:endpoint, $apikey, $tid, $type)
};

(:~
 : Pull details for a specific template to help support editing.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templateinfo.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $tid the template id - get from templates()
 : @param $type the template type to load - one of 'user', 'gallery', 'base'
 :
 : @return An array of info to be used when editing
 :)
declare sequential function mailchimp:template-info($endpoint-url as xs:string, $apikey as xs:string, $tid as xs:integer, $type as xs:string){
  xmlrpc:invoke($endpoint-url, "templateInfo", ($apikey, $tid, $type))
};

(:~
 :
 : Convenience function for <a href='#template-add-4'>template-add#4</a>.
 :
 : @see <a href='#template-add-4'>template-add#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $name the name for the template - names must be unique and a max of 50 bytes
 : @param $html a string specifying the entire template to be created. This is <strong>NOT</strong> campaign content. They are intended to utilize our <a href="http://www.mailchimp.com/resources/email-template-language/" target="_blank">template language</a>.
 :
 : @return The new template id, otherwise an error is thrown.
 :)
declare sequential function mailchimp:template-add($apikey as xs:string, $name as xs:string, $html as xs:string){
  mailchimp:template-add($mailchimp:endpoint, $apikey, $name, $html)
};

(:~
 : Create a new user template, <strong>NOT</strong> campaign content. These templates can then be applied while creating campaigns.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templateadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $name the name for the template - names must be unique and a max of 50 bytes
 : @param $html a string specifying the entire template to be created. This is <strong>NOT</strong> campaign content. They are intended to utilize our <a href="http://www.mailchimp.com/resources/email-template-language/" target="_blank">template language</a>.
 :
 : @return The new template id, otherwise an error is thrown.
 :)
declare sequential function mailchimp:template-add($endpoint-url as xs:string, $apikey as xs:string, $name as xs:string, $html as xs:string){
  xmlrpc:invoke($endpoint-url, "templateAdd", ($apikey, $name, $html))
};

(:~
 :
 : Convenience function for <a href='#template-update-4'>template-update#4</a>.
 :
 : @see <a href='#template-update-4'>template-update#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the id of the user template to update
 : @param $values s the values to updates - while both are optional, at least one should be provided. Both can be updated at the same time.
 :
 : @return True if the template was updated, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-update($apikey as xs:string, $id as xs:integer, $values as element(array)){
  mailchimp:template-update($mailchimp:endpoint, $apikey, $id, $values)
};

(:~
 : Replace the content of a user template, <strong>NOT</strong> campaign content.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templateupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the id of the user template to update
 : @param $values s the values to updates - while both are optional, at least one should be provided. Both can be updated at the same time.
 :
 : @return True if the template was updated, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-update($endpoint-url as xs:string, $apikey as xs:string, $id as xs:integer, $values as element(array)){
  xmlrpc:invoke($endpoint-url, "templateUpdate", ($apikey, $id, $values))
};

(:~
 :
 : Convenience function for <a href='#template-del-3'>template-del#3</a>.
 :
 : @see <a href='#template-del-3'>template-del#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the id of the user template to delete
 :
 : @return True if the template was deleted, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-del($apikey as xs:string, $id as xs:integer){
  mailchimp:template-del($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Delete (deactivate) a user template.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templatedel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the id of the user template to delete
 :
 : @return True if the template was deleted, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-del($endpoint-url as xs:string, $apikey as xs:string, $id as xs:integer){
  xmlrpc:invoke($endpoint-url, "templateDel", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#template-undel-3'>template-undel#3</a>.
 :
 : @see <a href='#template-undel-3'>template-undel#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $id the id of the user template to reactivate
 :
 : @return boolean true if the template was deleted, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-undel($apikey as xs:string, $id as xs:integer){
  mailchimp:template-undel($mailchimp:endpoint, $apikey, $id)
};

(:~
 : Undelete (reactivate) a user template.
 :
 : @see http://apidocs.mailchimp.com/rtfm/templateundel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $id the id of the user template to reactivate
 :
 : @return boolean true if the template was deleted, otherwise an error will be thrown
 :)
declare sequential function mailchimp:template-undel($endpoint-url as xs:string, $apikey as xs:string, $id as xs:integer){
  xmlrpc:invoke($endpoint-url, "templateUndel", ($apikey, $id))
};

(:~
 :
 : Convenience function for <a href='#get-account-details-2'>get-account-details#2</a>.
 :
 : @see <a href='#get-account-details-2'>get-account-details#2</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 :
 :
 : @return array containing the details for the account tied to this API Key
 :)
declare sequential function mailchimp:get-account-details($apikey as xs:string){
  mailchimp:get-account-details($mailchimp:endpoint, $apikey)
};

(:~
 : Retrieve lots of account information including payments made, plan info, some account stats, installed modules, contact info, and more.
 :
 : @see http://apidocs.mailchimp.com/rtfm/getaccountdetails.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 :
 : @return Array containing the details for the account tied to this API Key
 :)
declare sequential function mailchimp:get-account-details($endpoint-url as xs:string, $apikey as xs:string){
  xmlrpc:invoke($endpoint-url, "getAccountDetails", ($apikey))
};

(:~
 :
 : Convenience function for <a href='#generate-text-4'>generate-text#4</a>.
 :
 : @see <a href='#generate-text-4'>generate-text#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $type The type of content to parse. Must be one of: "html", "template", "url", "cid" (Campaign Id), or "tid" (Template Id)
 : @param $content The content to use. For "html" expects a single string value, "template" expects an array like you send to campaignCreate, "url" expects a valid &amp; public URL to pull from, "cid" expects a valid Campaign Id, and "tid" expects a valid Template Id on your account.
 :
 : @return The content pass in converted to text.
 :)
declare sequential function mailchimp:generate-text($apikey as xs:string, $type as xs:string, $content as item()){
  mailchimp:generate-text($mailchimp:endpoint, $apikey, $type, $content)
};

(:~
 : Have HTML content auto-converted to a text-only format. You can send: plain HTML, an array of Template content, an existing Campaign Id, or an existing Template Id. Note that this will <b>not</b> save anything to or update any of your lists, campaigns, or templates.
 :
 : @see http://apidocs.mailchimp.com/rtfm/generatetext.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $type The type of content to parse. Must be one of: "html", "template", "url", "cid" (Campaign Id), or "tid" (Template Id)
 : @param $content The content to use. For "html" expects a single string value, "template" expects an array like you send to campaignCreate, "url" expects a valid &amp; public URL to pull from, "cid" expects a valid Campaign Id, and "tid" expects a valid Template Id on your account.
 :
 : @return The content pass in converted to text.
 :)
declare sequential function mailchimp:generate-text($endpoint-url as xs:string, $apikey as xs:string, $type as xs:string, $content as item()){
  xmlrpc:invoke($endpoint-url, "generateText", ($apikey, $type, $content))
};

(:~
 :
 : Convenience function for <a href='#inline-css-4'>inline-css#4</a>.
 :
 : @see <a href='#inline-css-4'>inline-css#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $html Your HTML content
 : @param $strip_css optional Whether you want the CSS &amp;lt;style&amp;gt; tags stripped from the returned document. Defaults to false.
 :
 : @return Your HTML content with all CSS inlined, just like if we sent it.
 :)
declare sequential function mailchimp:inline-css($apikey as xs:string, $html as xs:string, $strip_css as xs:boolean){
  mailchimp:inline-css($mailchimp:endpoint, $apikey, $html, $strip_css)
};

(:~
 : Send your HTML content to have the CSS inlined and optionally remove the original styles.
 :
 : @see http://apidocs.mailchimp.com/rtfm/inlinecss.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $html Your HTML content
 : @param $strip_css optional Whether you want the CSS &amp;lt;style&amp;gt; tags stripped from the returned document. Defaults to false.
 :
 : @return Your HTML content with all CSS inlined, just like if we sent it.
 :)
declare sequential function mailchimp:inline-css($endpoint-url as xs:string, $apikey as xs:string, $html as xs:string, $strip_css as xs:boolean){
  xmlrpc:invoke($endpoint-url, "inlineCss", ($apikey, $html, $strip_css))
};

(:~
 :
 : Convenience function for <a href='#folders-3'>folders#3</a>.
 :
 : @see <a href='#folders-3'>folders#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $type optional the type of folders to return - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return Array of folder structs (see Returned Fields for details)
 :)
declare sequential function mailchimp:folders($apikey as xs:string, $type as xs:string){
  mailchimp:folders($mailchimp:endpoint, $apikey, $type)
};

(:~
 : List all the folders for a user account.
 :
 : @see http://apidocs.mailchimp.com/rtfm/folders.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $type optional the type of folders to return - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return Array of folder structs (see Returned Fields for details)
 :)
declare sequential function mailchimp:folders($endpoint-url as xs:string, $apikey as xs:string, $type as xs:string){
  xmlrpc:invoke($endpoint-url, "folders", ($apikey, $type))
};

(:~
 :
 : Convenience function for <a href='#folder-add-4'>folder-add#4</a>.
 :
 : @see <a href='#folder-add-4'>folder-add#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $name a unique name for a folder (max 100 bytes)
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return The folder_id of the newly created folder.
 :)
declare sequential function mailchimp:folder-add($apikey as xs:string, $name as xs:string, $type as xs:string){
  mailchimp:folder-add($mailchimp:endpoint, $apikey, $name, $type)
};

(:~
 : Add a new folder to file campaigns or autoresponders in.
 :
 : @see http://apidocs.mailchimp.com/rtfm/folderadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $name a unique name for a folder (max 100 bytes)
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return The folder_id of the newly created folder.
 :)
declare sequential function mailchimp:folder-add($endpoint-url as xs:string, $apikey as xs:string, $name as xs:string, $type as xs:string){
  xmlrpc:invoke($endpoint-url, "folderAdd", ($apikey, $name, $type))
};

(:~
 :
 : Convenience function for <a href='#folder-update-5'>folder-update#5</a>.
 :
 : @see <a href='#folder-update-5'>folder-update#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $fid the folder id to update - retrieve from folders()
 : @param $name a new, unique name for the folder (max 100 bytes)
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return True if the update worked, otherwise an exception is thrown
 :)
declare sequential function mailchimp:folder-update($apikey as xs:string, $fid as xs:integer, $name as xs:string, $type as xs:string){
  mailchimp:folder-update($mailchimp:endpoint, $apikey, $fid, $name, $type)
};

(:~
 : Update the name of a folder for campaigns or autoresponders.
 :
 : @see http://apidocs.mailchimp.com/rtfm/folderupdate.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $fid the folder id to update - retrieve from folders()
 : @param $name a new, unique name for the folder (max 100 bytes)
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return True if the update worked, otherwise an exception is thrown
 :)
declare sequential function mailchimp:folder-update($endpoint-url as xs:string, $apikey as xs:string, $fid as xs:integer, $name as xs:string, $type as xs:string){
  xmlrpc:invoke($endpoint-url, "folderUpdate", ($apikey, $fid, $name, $type))
};

(:~
 :
 : Convenience function for <a href='#folder-del-4'>folder-del#4</a>.
 :
 : @see <a href='#folder-del-4'>folder-del#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $fid the folder id to update - retrieve from folders()
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return True if the delete worked, otherwise an exception is thrown
 :)
declare sequential function mailchimp:folder-del($apikey as xs:string, $fid as xs:integer, $type as xs:string){
  mailchimp:folder-del($mailchimp:endpoint, $apikey, $fid, $type)
};

(:~
 : Delete a campaign or autoresponder folder. Note that this will simply make campaigns in the folder appear unfiled, they are not removed.
 :
 : @see http://apidocs.mailchimp.com/rtfm/folderdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $fid the folder id to update - retrieve from folders()
 : @param $type optional the type of folder to create - either "campaign" or "autoresponder". Defaults to "campaign"
 :
 : @return True if the delete worked, otherwise an exception is thrown
 :)
declare sequential function mailchimp:folder-del($endpoint-url as xs:string, $apikey as xs:string, $fid as xs:integer, $type as xs:string){
  xmlrpc:invoke($endpoint-url, "folderDel", ($apikey, $fid, $type))
};

(:~
 :
 : Convenience function for <a href='#ecomm-orders-5'>ecomm-orders#5</a>.
 :
 : @see <a href='#ecomm-orders-5'>ecomm-orders#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 500
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return Array the total matching orders and the specific orders for the requested page
 :)
declare sequential function mailchimp:ecomm-orders($apikey as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  mailchimp:ecomm-orders($mailchimp:endpoint, $apikey, $start, $limit, $since)
};

(:~
 : Retrieve the Ecommerce Orders for an account.
 :
 : @see http://apidocs.mailchimp.com/rtfm/ecommorders.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $start optional for large data sets, the page number to start at - defaults to 1st page of data (page 0)
 : @param $limit optional for large data sets, the number of results to return - defaults to 100, upper limit set at 500
 : @param $since optional pull only messages since this time - use YYYY-MM-DD HH:II:SS format in <strong>GMT</strong>
 :
 : @return Array the total matching orders and the specific orders for the requested page
 :)
declare sequential function mailchimp:ecomm-orders($endpoint-url as xs:string, $apikey as xs:string, $start as xs:integer, $limit as xs:integer, $since as xs:string){
  xmlrpc:invoke($endpoint-url, "ecommOrders", ($apikey, $start, $limit, $since))
};

(:~
 :
 : Convenience function for <a href='#ecomm-order-add-3'>ecomm-order-add#3</a>.
 :
 : @see <a href='#ecomm-order-add-3'>ecomm-order-add#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $order an array of information pertaining to the order that has completed. Use the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/ecommorderadd.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return True if the data is saved, otherwise an error is thrown.
 :)
declare sequential function mailchimp:ecomm-order-add($apikey as xs:string, $order as element(array)){
  mailchimp:ecomm-order-add($mailchimp:endpoint, $apikey, $order)
};

(:~
 : Import Ecommerce Order Information to be used for Segmentation.
 :
 : @see http://apidocs.mailchimp.com/rtfm/ecommorderadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $order an array of information pertaining to the order that has completed. Use the following keys. See <a href='http://apidocs.mailchimp.com/rtfm/ecommorderadd.func.php'>Mailchimp API documentation</a> for more information about the parameter structure.
 :
 : @return True if the data is saved, otherwise an error is thrown.
 :)
declare sequential function mailchimp:ecomm-order-add($endpoint-url as xs:string, $apikey as xs:string, $order as element(array)){
  xmlrpc:invoke($endpoint-url, "ecommOrderAdd", ($apikey, $order))
};

(:~
 :
 : Convenience function for <a href='#ecomm-order-del-4'>ecomm-order-del#4</a>.
 :
 : @see <a href='#ecomm-order-del-4'>ecomm-order-del#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $store_id the store id the order belongs to
 : @param $order_id the order id (generated by the store) to delete
 :
 : @return True if an order is deleted, otherwise an error is thrown.
 :)
declare sequential function mailchimp:ecomm-order-del($apikey as xs:string, $store_id as xs:string, $order_id as xs:string){
  mailchimp:ecomm-order-del($mailchimp:endpoint, $apikey, $store_id, $order_id)
};

(:~
 : Delete Ecommerce Order Information used for segmentation. This will generally be used by ecommerce package plugins <a href="/plugins/ecomm360.phtml">that we provide</a> or by 3rd part system developers.
 :
 : @see http://apidocs.mailchimp.com/rtfm/ecommorderdel.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $store_id the store id the order belongs to
 : @param $order_id the order id (generated by the store) to delete
 :
 : @return True if an order is deleted, otherwise an error is thrown.
 :)
declare sequential function mailchimp:ecomm-order-del($endpoint-url as xs:string, $apikey as xs:string, $store_id as xs:string, $order_id as xs:string){
  xmlrpc:invoke($endpoint-url, "ecommOrderDel", ($apikey, $store_id, $order_id))
};

(:~
 :
 : Convenience function for <a href='#lists-for-email-3'>lists-for-email#3</a>.
 :
 : @see <a href='#lists-for-email-3'>lists-for-email#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $email_address the email address to check OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 :
 : @return An array of list_ids the member is subscribed to.
 :)
declare sequential function mailchimp:lists-for-email($apikey as xs:string, $email_address as xs:string){
  mailchimp:lists-for-email($mailchimp:endpoint, $apikey, $email_address)
};

(:~
 : Retrieve all List Ids a member is subscribed to.
 :
 : @see http://apidocs.mailchimp.com/rtfm/listsforemail.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $email_address the email address to check OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 :
 : @return An array of list_ids the member is subscribed to.
 :)
declare sequential function mailchimp:lists-for-email($endpoint-url as xs:string, $apikey as xs:string, $email_address as xs:string){
  xmlrpc:invoke($endpoint-url, "listsForEmail", ($apikey, $email_address))
};

(:~
 :
 : Convenience function for <a href='#campaigns-for-email-3'>campaigns-for-email#3</a>.
 :
 : @see <a href='#campaigns-for-email-3'>campaigns-for-email#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $email_address the email address to unsubscribe OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 :
 : @return An array of campaign_ids the member received
 :)
declare sequential function mailchimp:campaigns-for-email($apikey as xs:string, $email_address as xs:string){
  mailchimp:campaigns-for-email($mailchimp:endpoint, $apikey, $email_address)
};

(:~
 : Retrieve all Campaigns Ids a member was sent.
 :
 : @see http://apidocs.mailchimp.com/rtfm/campaignsforemail.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 : @param $email_address the email address to unsubscribe OR the email "id" returned from listMemberInfo, Webhooks, and Campaigns
 :
 : @return An array of campaign_ids the member received
 :)
declare sequential function mailchimp:campaigns-for-email($endpoint-url as xs:string, $apikey as xs:string, $email_address as xs:string){
  xmlrpc:invoke($endpoint-url, "campaignsForEmail", ($apikey, $email_address))
};

(:~
 :
 : Convenience function for <a href='#chimp-chatter-2'>chimp-chatter#2</a>.
 :
 : @see <a href='#chimp-chatter-2'>chimp-chatter#2</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 :
 :
 : @return An array of chatter messages and properties
 :)
declare sequential function mailchimp:chimp-chatter($apikey as xs:string){
  mailchimp:chimp-chatter($mailchimp:endpoint, $apikey)
};

(:~
 : Return the current Chimp Chatter messages for an account.
 :
 : @see http://apidocs.mailchimp.com/rtfm/chimpchatter.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 :
 : @return An array of chatter messages and properties
 :)
declare sequential function mailchimp:chimp-chatter($endpoint-url as xs:string, $apikey as xs:string){
  xmlrpc:invoke($endpoint-url, "chimpChatter", ($apikey))
};

(:~
 :
 : Convenience function for <a href='#apikeys-5'>apikeys#5</a>.
 :
 : @see <a href='#apikeys-5'>apikeys#5</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key for your account
 : @param $expired optional - whether or not to include expired keys, defaults to false
 :
 : @return An array of API keys.
 :)
declare sequential function mailchimp:apikeys($username as xs:string, $password as xs:string, $apikey as xs:string, $expired as xs:boolean){
  mailchimp:apikeys($mailchimp:endpoint, $username, $password, $apikey, $expired)
};

(:~
 : Retrieve a list of all MailChimp API Keys for this User.
 :
 : @see http://apidocs.mailchimp.com/rtfm/apikeys.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $username Your MailChimp user name
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key for your account
 : @param $expired optional - whether or not to include expired keys, defaults to false
 :
 : @return An array of API keys.
 :)
declare sequential function mailchimp:apikeys($endpoint-url as xs:string, $username as xs:string, $password as xs:string, $apikey as xs:string, $expired as xs:boolean){
  xmlrpc:invoke($endpoint-url, "apikeys", ($username, $password, $apikey, $expired))
};

(:~
 :
 : Convenience function for <a href='#apikey-add-4'>apikey-add#4</a>.
 :
 : @see <a href='#apikey-add-4'>apikey-add#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key
 :
 : @return A new API Key that can be immediately used.
 :)
declare sequential function mailchimp:apikey-add($username as xs:string, $password as xs:string, $apikey as xs:string){
  mailchimp:apikey-add($mailchimp:endpoint, $username, $password, $apikey)
};

(:~
 : Add an API Key to your account. We will generate a new key for you and return it.
 :
 : @see http://apidocs.mailchimp.com/rtfm/apikeyadd.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $username Your MailChimp user name
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key
 :
 : @return A new API Key that can be immediately used.
 :)
declare sequential function mailchimp:apikey-add($endpoint-url as xs:string, $username as xs:string, $password as xs:string, $apikey as xs:string){
  xmlrpc:invoke($endpoint-url, "apikeyAdd", ($username, $password, $apikey))
};

(:~
 :
 : Convenience function for <a href='#apikey-expire-4'>apikey-expire#4</a>.
 :
 : @see <a href='#apikey-expire-4'>apikey-expire#4</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key that you wish to expire
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:apikey-expire($username as xs:string, $password as xs:string, $apikey as xs:string){
  mailchimp:apikey-expire($mailchimp:endpoint, $username, $password, $apikey)
};

(:~
 : Expire a Specific API Key. Note that if you expire all of your keys, just visit <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a> to create a new one. If you are trying to shut off access to your account for an old developer, change your MailChimp password, then expire all of the keys they had access to. Note that this takes effect immediately, so make sure you replace the keys in any working application before expiring them! Consider yourself warned...
 :
 : @see http://apidocs.mailchimp.com/rtfm/apikeyexpire.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $username Your MailChimp user name
 : @param $password Your MailChimp password
 : @param $apikey Any valid API Key that you wish to expire
 :
 : @return True if it worked, otherwise an error is thrown.
 :)
declare sequential function mailchimp:apikey-expire($endpoint-url as xs:string, $username as xs:string, $password as xs:string, $apikey as xs:string){
  xmlrpc:invoke($endpoint-url, "apikeyExpire", ($username, $password, $apikey))
};

(:~
 :
 : Convenience function for <a href='#login-3'>login#3</a>.
 :
 : @see <a href='#login-3'>login#3</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $password Your MailChimp password
 :
 : @return API Key.
 :)
declare sequential function mailchimp:login($username as xs:string, $password as xs:string){
  mailchimp:login($mailchimp:endpoint, $username, $password)
};

(:~
 : Login Mailchimp User.
 :
 : @see http://apidocs.mailchimp.com/rtfm/login.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $username Your MailChimp user name
 : @param $password Your MailChimp password
 :
 : @return API Key.
 :)
declare sequential function mailchimp:login($endpoint-url as xs:string, $username as xs:string, $password as xs:string){
  xmlrpc:invoke($endpoint-url, "login", ($username, $password))
};

(:~
 :
 : Convenience function for <a href='#ping-2'>ping#2</a>.
 :
 : @see <a href='#ping-2'>ping#2</a>
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 :
 :
 : @return Returns "Everything's Chimpy!" if everything is chimpy, otherwise returns an error message
 :)
declare sequential function mailchimp:ping($apikey as xs:string){
  mailchimp:ping($mailchimp:endpoint, $apikey)
};

(:~
 : "Ping" the MailChimp API - a simple method you can call that will return a constant value as long as everything is good. Note than unlike most all of our methods, we don't throw an Exception if we are having issues. You will simply receive a different string back that will explain our view on what is going on.
 :
 : @see http://apidocs.mailchimp.com/rtfm/ping.func.php
 :
 : @param $endpoint-url Mailchimp endpoint URL, e.g. http://us1.api.mailchimp.com/1.3/
 : @param $apikey a valid API Key for your user account. Get by visiting <a href="http://admin.mailchimp.com/account/api" target="_blank">your API dashboard</a>
 :
 : @return Returns "Everything's Chimpy!" if everything is chimpy, otherwise returns an error message
 :)
declare sequential function mailchimp:ping($endpoint-url as xs:string, $apikey as xs:string){
  xmlrpc:invoke($endpoint-url, "ping", ($apikey))
};