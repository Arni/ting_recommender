  <?php
/**
 * @file
 * This plugin generates a search result based on a new materials node. It's
 * mainly used to override the default page for this node type (node/%node).
 */

$plugin = array(
  'title' => t('Ting Recommender'),
  'description' => t('Show recommendation'),
  'single' => TRUE,
  //'edit form' => 'ting_inspiration_list_content_type_edit_form',
  'render callback' => 'ting_recommender_content_type_render',
  'category' => t('Ting'),
  'required context' => new ctools_context_required(t('Ting object'), 'ting_object'),
  'render last' => TRUE,
);

/**
 * Render the ting new materials results results amount block.
 */
function ting_recommender_content_type_render($subtype, $conf, $panel_args, $context) {
  // Define the return block.
  $block = new stdClass();
  drupal_add_js('https://cdn.bibspire.dk/ddbcms.js', 'external');
  $object = isset($context->data) ? ($context->data) : NULL;
  $data = '';
  if (isset($object)) {
    $data = 'data-ting-object-id="' . $object->getId() . '"';
  }
  
  // Set block content.
  $block->content = '<a name="recommender"></a><div id="ting-recommender" ' . $data . '></div>';
  return $block;
}


