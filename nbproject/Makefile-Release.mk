#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ast/Assignment.o \
	${OBJECTDIR}/src/ast/Bracket.o \
	${OBJECTDIR}/src/ast/CurrVarDeclaration.o \
	${OBJECTDIR}/src/ast/InputInstruction.o \
	${OBJECTDIR}/src/ast/Instruction.o \
	${OBJECTDIR}/src/ast/InstructionLink.o \
	${OBJECTDIR}/src/ast/NumVarDeclaration.o \
	${OBJECTDIR}/src/ast/Operator.o \
	${OBJECTDIR}/src/ast/PrintVar.o \
	${OBJECTDIR}/src/ast/Program.o \
	${OBJECTDIR}/src/ast/RValue.o \
	${OBJECTDIR}/src/ast/VarDeclaration.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/parser/Parser.o \
	${OBJECTDIR}/src/parser/Scanner.o \
	${OBJECTDIR}/src/parser/Token.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tkom-currency

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tkom-currency: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tkom-currency ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/ast/Assignment.o: src/ast/Assignment.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/Assignment.o src/ast/Assignment.cpp

${OBJECTDIR}/src/ast/Bracket.o: src/ast/Bracket.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/Bracket.o src/ast/Bracket.cpp

${OBJECTDIR}/src/ast/CurrVarDeclaration.o: src/ast/CurrVarDeclaration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/CurrVarDeclaration.o src/ast/CurrVarDeclaration.cpp

${OBJECTDIR}/src/ast/InputInstruction.o: src/ast/InputInstruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/InputInstruction.o src/ast/InputInstruction.cpp

${OBJECTDIR}/src/ast/Instruction.o: src/ast/Instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/Instruction.o src/ast/Instruction.cpp

${OBJECTDIR}/src/ast/InstructionLink.o: src/ast/InstructionLink.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/InstructionLink.o src/ast/InstructionLink.cpp

${OBJECTDIR}/src/ast/NumVarDeclaration.o: src/ast/NumVarDeclaration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/NumVarDeclaration.o src/ast/NumVarDeclaration.cpp

${OBJECTDIR}/src/ast/Operator.o: src/ast/Operator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/Operator.o src/ast/Operator.cpp

${OBJECTDIR}/src/ast/PrintVar.o: src/ast/PrintVar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/PrintVar.o src/ast/PrintVar.cpp

${OBJECTDIR}/src/ast/Program.o: src/ast/Program.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/Program.o src/ast/Program.cpp

${OBJECTDIR}/src/ast/RValue.o: src/ast/RValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/RValue.o src/ast/RValue.cpp

${OBJECTDIR}/src/ast/VarDeclaration.o: src/ast/VarDeclaration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/ast
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ast/VarDeclaration.o src/ast/VarDeclaration.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/parser/Parser.o: src/parser/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parser/Parser.o src/parser/Parser.cpp

${OBJECTDIR}/src/parser/Scanner.o: src/parser/Scanner.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parser/Scanner.o src/parser/Scanner.cpp

${OBJECTDIR}/src/parser/Token.o: src/parser/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parser/Token.o src/parser/Token.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tkom-currency

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
