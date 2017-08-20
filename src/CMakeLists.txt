message(STATUS "Construindo programa")

set(target uBase)

set(sources
	main.c
	help.c
	interpretar.c
	criar.c
	remover.c
	ordenar.c
	compactar.c
	descompactar.c
	bibliotecaRemover.c
	bibliotecaAlocacao.c
	bibliotecaStrings.c
	bibliotecaOperacoes.c
	bibliotecaCompactacao.c
	bibliotecaDescompactacao.c
	bibliotecaCriar.c
	susbtituicao.c
	selecaonatural.c
	huffman.c
	bibliotecaCriar.c
	susbtituicao.c
	selecaonatural.c

	inserir.c

	indexsecundaria.c
)

add_executable(${target} ${sources})
target_link_libraries(${target})
