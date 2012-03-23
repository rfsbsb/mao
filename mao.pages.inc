<?php

function mao_page_simple() {
  return array('#markup' => '<p>' . t('Simple page: The quick brown fox jumps over the lazy dog.') . '</p>');
}

function mao_page_tab($node) {
  $node_base = node_view($node);
  return array('#markup' => '<p>' . t('This is the node title: '). $node->title . '</p>');
}
