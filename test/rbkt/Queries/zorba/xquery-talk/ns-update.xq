for $i in doc('FitnessCenter.xml')//*
   return rename node $i as QName('http://www.gym.com', concat('gym:', local-name($i)));
fn:doc('FitnessCenter.xml')