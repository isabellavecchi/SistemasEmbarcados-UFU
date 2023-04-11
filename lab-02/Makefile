#targets: prerequisites
#	recipe

## Variaveis
# $< é o primeiro elemento da lista de pré-requisitos
# $@ é o alvo da regra

## Funcoes
# $(basename names…) -> retorna o nome dos arquivos sem a extensão
# $(patsubst pattern,replacement,text)




# Ferramentas do toolchain

CC = arm-none-eabi-gcc
RM = rm -rf

# Diretorios arquivos objeto e de dependencias que serao salvos

OBJDIR = build
DEPDIR = .deps

# Arquivos a serem compilados

SRCS = startup.c \
        main.c

#Flags do compilador e linker

CFLAGS = -g -mcpu=cortex-m4 -mthumb -Wall -O0
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d #-MP para criar um target vazio na lista de dependencias




# Gera uma lista de arquivos objeto utilizando os arquivos fonte


#	Para o Makefile, apenas a primeira regra roda quando rodamos o comando "make"
# no entanto... podemos contornar o problema com o target all e seus pré-requisitos:
# all: startup.o main.o

# main.o: main.c
# 	${CC} -c ${CFLAGS} $< -o $@
# startup.o: startup.c
# 	${CC} -c ${CFLAGS} $< -o $@

#o bloco acima foi subsituído por este:
# OBJS = $(patsubst %, %.o, $(basename $(SRCS)))

# Gera lista de arquivos objeto e cria diretorio onde serao salvos
OBJS = $(patsubst %, $(OBJDIR)/%.o, $(basename $(SRCS)))
$(shell mkdir -p $(dir $(OBJS)) > /dev/null)

# Gera lista de arquivos de lista dependencia e cria diretorio onde serao salvos
DEPS = $(patsubst %, $(DEPDIR)/%.d, $(basename $(SRCS)))
$(shell mkdir -p $(dir $(DEPS)) > /dev/null)

all: ${OBJS}

# %.o: %.c
$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	${CC} -c ${CFLAGS} ${DEPFLAGS} $< -o $@


# Cria um novo target para cada arquivo de dependencia possivel
# .deps/startup.d:
# .deps/main.d:
$(DEPS):

# Inclui conteudo dos arquivos de dependencia
### build/startup.o: startup.c
### build/main.o: main.c config.h
-include $(DEPS)

.PHONY: clean
clean:
	$(RM) $(OBJDIR) $(DEPDIR)