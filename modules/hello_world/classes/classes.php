<?php

class NodeEntityFieldQuery extends EntityFieldQuery
{
    // Class defaults.
    public function __construct()
    {
        $this
            ->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'hello_world_article')
            ->propertyCondition('status', 1)
            ->propertyOrderBy('created', 'ASC');
    }

    //exclude current node
    public function excludeNode($nid = '')
    {
        if ($nid = '') {
            $object = menu_get_object();
            $nid = $object->nid;
        }
        if (!empty($nid) && $this->entityConditions['entity_type']['value'] === 'node') {
            $this->propertyCondition('nid', $nid, '<>');
        }
        return $this;
    }
}
