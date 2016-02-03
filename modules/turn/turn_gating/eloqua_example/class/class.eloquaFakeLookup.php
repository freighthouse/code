<?php

class EloquaFakeLookup
{
    public $data = null;  // parse eloqua javascript data placed into array
    
    public function __construct($sid) 
    {
        $sub = webform_menu_submission_load($sid, 24);
        $this->data = $sub;
    }
    
    // returns data safely from data array by name (only valid for contacts/prospects/visitors lookup)
    public function getField($name) 
    {
        return isset($this->data[$name]) ? $this->data[$name] : '';
    }
}
