import module namespace hmac = "http://www.zorba-xquery.com/modules/security/hmac";

hmac:sha1("foo", "bar"),
hmac:sha1("GET&amp;http%3A%2F%2Ftwitter.com%2Faccount%2Fverify_credentials.xml&amp;oauth_consumer_key%3DAJNRLGd7aT0SvQMLjudog%26oauth_nonce%3D4996802908718844015%26oauth_signature_method%3DHMAC-SHA1%26oauth_timestamp%3D1274195088%26oauth_token%3D131201600-tHRlNpwN6JmJsNjDYBgHgccV9fvdOD5e4f8j3BZd%26oauth_version%3D1.0", "TfV0JLBWBBslSuCLwrWcC8q4PxPGmFSgyhc4ewHNY4")
