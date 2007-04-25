include ../Makefile.header
SUFX=do
BUILD=Build

primitive_values :	primitive_values.h primitive_values.cpp
	g++ ${OPT} -c -o ${BUILD}/primitive_values.${SUFX} primitive_values.cpp

primitive_values_test :	primitive_values.h primitive_values.cpp primitive_values_test.cpp
	g++ ${OPT} -o ${BUILD}/primitive_values_test \
		${BUILD}/primitive_values.${SUFX} \
		primitive_values_test.cpp

ft_options :	ft_options.h ft_options.cpp
	g++ ${OPT} -c -o ${BUILD}/ft_options.${SUFX} ft_options.cpp

ft_values :	ft_values.h ft_values.cpp
	g++ ${OPT} -c -o ${BUILD}/ft_values.${SUFX} ft_values.cpp

update_values :	update_values.h update_values.cpp
	g++ -Wall ${OPT} -c -o ${BUILD}/update_values.${SUFX} update_values.cpp

all : \
	primitive_values \
	ft_options \
	ft_values \
	update_values

