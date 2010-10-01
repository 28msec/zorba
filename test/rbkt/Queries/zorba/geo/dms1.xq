import module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";

(geoproj:dms-to-deg("10d10'10"),
geoproj:dms-to-deg("10d"),
geoproj:dms-to-deg("10"),
geoproj:dms-to-deg("10S"),
geoproj:dms-to-deg("10dS"),
geoproj:dms-to-deg("10o10N"),
geoproj:dms-to-deg("10d10.1S"),
geoproj:dms-to-deg("-10d10.1S"),
geoproj:dms-to-deg("10d10'10.1W"),
geoproj:dms-to-deg("10d10m10.1E"),
geoproj:dms-to-deg("180d10'10.1W"))