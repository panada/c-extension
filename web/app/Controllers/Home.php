<?php
namespace Controllers;

class Home
{
    public function index()
    {
        echo 'Hello world Mandirva!';
    }
    
    public function name()
    {
        echo 'kandar<br>';
        
        print_r( func_get_args() );
    }
}
