<?php

/**
* Page callback: Current posts settings
*
* @see mao_menu()
*/
function mao_form($form, &$form_state) {
  $vocabs = array_keys(taxonomy_get_vocabularies());

  taxonomy_get_tree($vocabs[0]);

  $form['mao_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of posts'),
    '#default_value' => variable_get('mao_max', 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The maximum number of links to display in the block.'),
    '#required' => TRUE,
  );

  $types = node_type_get_types();

  $options = array(
    0 => t('All')
  );

  foreach ($types as $id => $type) {
    $options[$id] = $type->name;
  }

  $form['mao_type'] = array(
    '#type'  => 'select',
    '#title' => t('Content Type'),
    '#default_value' => variable_get('mao_type', 0),
    '#description' => t('Choose the type to show at the block'),
    '#options' => $options
  );


  return system_settings_form($form);
}

/**
* Implements validation from the Form API.
*
* @param $form
*   A structured array containing the elements and properties of the form.
* @param $form_state
*   An array that stores information about the form's current state
*   during processing.
*/
function mao_form_validate($form, &$form_state){
  $max_num = $form_state['values']['mao_max'];
  if (!ctype_digit($max_num)){
    form_set_error('mao_max', t('You must enter a number for the maximum number of posts to display.'));
  }
}
