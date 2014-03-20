
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "panada.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"

zend_class_entry *panada_gear_ce;
zend_class_entry *panada_resources_config_ce;
zend_class_entry *panada_resources_runexception_ce;
zend_class_entry *panada_resources_uri_ce;
zend_class_entry *panada_test_ce;

ZEND_DECLARE_MODULE_GLOBALS(panada)

static PHP_MINIT_FUNCTION(panada)
{
#if PHP_VERSION_ID < 50500
	const char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		char *tmp = calloc(strlen(old_lc_all)+1, 1);
		memcpy(tmp, old_lc_all, strlen(old_lc_all));
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Panada_Gear);
	ZEPHIR_INIT(Panada_Resources_Config);
	ZEPHIR_INIT(Panada_Resources_RunException);
	ZEPHIR_INIT(Panada_Resources_Uri);
	ZEPHIR_INIT(Panada_Test);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(panada)
{
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC)
{

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

#ifndef ZEPHIR_RELEASE
static void zephir_fcall_cache_dtor(void *pData)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**)pData;
	free(*entry);
}
#endif

static int zephir_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	zephir_fcall_cache_entry **entry = (zephir_fcall_cache_entry**)pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2*sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2*sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

#ifndef ZEPHIR_RELEASE
if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
	return ZEND_HASH_APPLY_REMOVE;
}
#else
if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
	return ZEND_HASH_APPLY_REMOVE;
}
#endif

#if PHP_VERSION_ID >= 50400
if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
	return ZEND_HASH_APPLY_REMOVE;
}
#else
if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
	return ZEND_HASH_APPLY_REMOVE;
}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

static PHP_RINIT_FUNCTION(panada)
{

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//panada_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(panada)
{

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	/*if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}*/

	zend_hash_apply_with_arguments(ZEPHIR_GLOBAL(fcache) TSRMLS_CC, zephir_cleanup_fcache, 0);

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(panada)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PANADA_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PANADA_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PANADA_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PANADA_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PANADA_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(panada)
{
	zephir_memory_entry *start;
	int num_preallocated_frames = 24;
	size_t i;

	php_zephir_init_globals(panada_globals TSRMLS_CC);

	/* pre-allocated memory frames */
	start = (zephir_memory_entry *) pecalloc(num_preallocated_frames, sizeof(zephir_memory_entry), 1);

	for (i = 0; i < num_preallocated_frames; ++i) {
		start[i].addresses = pecalloc(16, sizeof(zval*), 1);
		start[i].capacity = 16;
		start[i].hash_addresses = pecalloc(4, sizeof(zval*), 1);
		start[i].hash_capacity = 4;

#ifndef ZEPHIR_RELEASE
		start[i].permanent = 1;
#endif
	}

	start[0].next = &start[1];
	start[num_preallocated_frames - 1].prev = &start[num_preallocated_frames - 2];

	for (i = 1; i < num_preallocated_frames - 1; ++i) {
		start[i].next = &start[i + 1];
		start[i].prev = &start[i - 1];
	}

	panada_globals->start_memory = start;
	panada_globals->end_memory = start + num_preallocated_frames;

	/* Function call cache */
	panada_globals->fcache = pemalloc(sizeof(HashTable), 1);
#ifndef ZEPHIR_RELEASE
	zend_hash_init(panada_globals->fcache, 128, NULL, zephir_fcall_cache_dtor, 1);
#else
	zend_hash_init(panada_globals->fcache, 128, NULL, NULL, 1);
#endif

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(panada_globals->global_false);
	INIT_PZVAL(panada_globals->global_false);
	ZVAL_FALSE(panada_globals->global_false);
	Z_ADDREF_P(panada_globals->global_false);

	ALLOC_PERMANENT_ZVAL(panada_globals->global_true);
	INIT_PZVAL(panada_globals->global_true);
	ZVAL_TRUE(panada_globals->global_true);
	Z_ADDREF_P(panada_globals->global_true);

	ALLOC_PERMANENT_ZVAL(panada_globals->global_null);
	INIT_PZVAL(panada_globals->global_null);
	ZVAL_NULL(panada_globals->global_null);
	Z_ADDREF_P(panada_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(panada)
{
	size_t i;
	int num_preallocated_frames = 24;

	assert(panada_globals->start_memory != NULL);

	for (i = 0; i < num_preallocated_frames; ++i) {
		pefree(panada_globals->start_memory[i].hash_addresses, 1);
		pefree(panada_globals->start_memory[i].addresses, 1);
	}

	pefree(panada_globals->start_memory, 1);
	panada_globals->start_memory = NULL;

	zend_hash_destroy(panada_globals->fcache);
	pefree(panada_globals->fcache, 1);
	panada_globals->fcache = NULL;
}

zend_module_entry panada_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PANADA_EXTNAME,
	NULL,
	PHP_MINIT(panada),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(panada),
#else
	NULL,
#endif
	PHP_RINIT(panada),
	PHP_RSHUTDOWN(panada),
	PHP_MINFO(panada),
	PHP_PANADA_VERSION,
	ZEND_MODULE_GLOBALS(panada),
	PHP_GINIT(panada),
	PHP_GSHUTDOWN(panada),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PANADA
ZEND_GET_MODULE(panada)
#endif
