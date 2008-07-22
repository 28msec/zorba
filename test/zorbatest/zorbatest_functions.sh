latest_snapshot () {
  (cd $ROOT/snapshots; ls -rd *-*-*-*_*_* 2>/dev/null | head -1)
}


#
# Check out sources
#

# Mandatory vars: $REV, $SRC
# Optional vars:  $LASTREV
# Modifies $REV.
# Creates svn_log.xml

update_src () {

local NEWREV;

if test "x$REV" != "xlocal"; then
  echo 'Updating sources...'
  echo $HOME
  id
  NEWREV=`svn update -r $REV $SRC | perl -ne 'if (/ revision ([0-9]+)\./) { print $1; }'`
  REV=$NEWREV

  if test -z $REV; then echo 'Could not update sources'; exit 1; fi
  if test "x$REV" = "x$LASTREV"; then echo No changes, exiting; exit; fi
fi

rm -f svn_log.xml
if test "x$LASTREV" != "x" -a "x$REV" != "xlocal" -a "x$REV" != "x$LASTREV"; then
    svn log --xml $SRC -r`expr $LASTREV + 1`:$REV >svn_log.xml
fi
test -f svn_log.xml -a -s svn_log.xml || echo '<?xml version="1.0" encoding="UTF-8"?><log />' >svn_log.xml

}  # update_src
