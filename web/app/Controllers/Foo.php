<?php
namespace Controllers;

class Foo
{
    public function index()
    {
        echo 'foo';
    }
    
    public function name()
    {
        echo __METHOD__;
        
        print_r( func_get_args() );
    }
}