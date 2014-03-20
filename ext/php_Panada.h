
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PANADA_H
#define PHP_PANADA_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_PANADA_NAME        "panada"
#define PHP_PANADA_VERSION     "0.0.1"
#define PHP_PANADA_EXTNAME     "panada"
#define PHP_PANADA_AUTHOR      ""
#define PHP_PANADA_ZEPVERSION  "0.3.10a"
#define PHP_PANADA_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(panada)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(panada)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(panada)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(panada_globals_id, zend_panada_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (panada_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_panada_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(panada_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(panada_globals)
#endif

#define zephir_globals panada_globals
#define zend_zephir_globals zend_panada_globals

extern zend_module_entry panada_module_entry;
#define phpext_panada_ptr &panada_module_entry

#endif
