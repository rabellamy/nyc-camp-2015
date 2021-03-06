<?php
/**
 * @file
 * Default exported views.
 */

/**
 * Implements hook_views_default_views().
 */
function ticket_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ticket_registration';
  $view->description = 'Display a list of all registrations for a given ticket type';
  $view->tag = 'ticket';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Ticket: Registrations by type';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['display_comment'] = 'Add ticket registration displays to customize the output.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'created' => 'created',
    'active' => 'active',
    'view_registration' => 'view_registration',
    'edit_registration' => 'view_registration',
    'cancel_registration' => 'view_registration',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'active' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_registration' => array(
      'align' => '',
      'separator' => '&nbsp; | &nbsp;',
      'empty_column' => 0,
    ),
    'edit_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no ticket registrations.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Ticket registration: Registrant */
  $handler->display->display_options['relationships']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['relationships']['author_uid']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'author_uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'author_uid';
  /* Field: Ticket registration: Ticket registration state */
  $handler->display->display_options['fields']['ticket_state']['id'] = 'ticket_state';
  $handler->display->display_options['fields']['ticket_state']['table'] = 'field_data_ticket_state';
  $handler->display->display_options['fields']['ticket_state']['field'] = 'ticket_state';
  $handler->display->display_options['fields']['ticket_state']['label'] = 'Status';
  /* Field: Ticket registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Ticket registration: Link */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Operations';
  /* Field: Ticket registration: Edit link */
  $handler->display->display_options['fields']['edit_registration']['id'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['edit_registration']['field'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['label'] = '';
  $handler->display->display_options['fields']['edit_registration']['element_label_colon'] = FALSE;
  /* Field: Ticket registration: Cancel link */
  $handler->display->display_options['fields']['cancel_registration']['id'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['cancel_registration']['field'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['label'] = '';
  $handler->display->display_options['fields']['cancel_registration']['element_label_colon'] = FALSE;
  /* Contextual filter: Ticket registration: Ticket type ID (bundle) */
  $handler->display->display_options['arguments']['bundle']['id'] = 'bundle';
  $handler->display->display_options['arguments']['bundle']['table'] = 'ticket_registration';
  $handler->display->display_options['arguments']['bundle']['field'] = 'bundle';
  $handler->display->display_options['arguments']['bundle']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['bundle']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['bundle']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bundle']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bundle']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  // Enable Recent Registrations panel pane if panels module is enabled
  if (module_exists('panels')) {
    /* Display: Recent Registrations */
    $handler = $view->new_display('panel_pane', 'Recent Registrations', 'panel_pane_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Recent Registrations';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['header'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: Ticket registration: Registrant */
    $handler->display->display_options['relationships']['author_uid']['id'] = 'author_uid';
    $handler->display->display_options['relationships']['author_uid']['table'] = 'ticket_registration';
    $handler->display->display_options['relationships']['author_uid']['field'] = 'author_uid';
    $handler->display->display_options['relationships']['author_uid']['required'] = TRUE;
    /* Relationship: Ticket registration: Ticket Type */
    $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
    $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
    $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
    $handler->display->display_options['relationships']['ticket_type_ttid']['label'] = 'Ticket Type';
    $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: Ticket type: Entity ID */
    $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
    $handler->display->display_options['arguments']['entity_id']['table'] = 'ticket_type';
    $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
    $handler->display->display_options['arguments']['entity_id']['relationship'] = 'ticket_type_ttid';
    $handler->display->display_options['arguments']['entity_id']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['entity_id']['specify_validation'] = TRUE;
    $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'node';
    $handler->display->display_options['arguments']['entity_id']['validate_options']['types'] = array(
      'event' => 'event',
    );
    $handler->display->display_options['arguments']['entity_id']['validate_options']['access'] = TRUE;
  }
  $export['ticket_registration'] = $view;

  $view = new view();
  $view->name = 'ticket_user';
  $view->description = 'Display a list of all registration by a given user';
  $view->tag = 'default';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Ticket: Registrations by user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ticket: Registrations';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entity' => 'entity',
    'ticket_type_label' => 'ticket_type_label',
    'created' => 'created',
    'view_registration' => 'view_registration',
    'edit_registration' => 'view_registration',
    'cancel_registration' => 'view_registration',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ticket_type_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_registration' => array(
      'align' => '',
      'separator' => '&nbsp; | &nbsp;',
      'empty_column' => 0,
    ),
    'edit_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_registration' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no ticket registrations.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Ticket registration: Ticket Type */
  $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
  /* Relationship: Ticket registration: Attendee */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['ticket_state_target_id']['id'] = 'ticket_state_target_id';
  $handler->display->display_options['relationships']['ticket_state_target_id']['table'] = 'field_data_ticket_state';
  $handler->display->display_options['relationships']['ticket_state_target_id']['field'] = 'ticket_state_target_id';
  $handler->display->display_options['relationships']['ticket_state_target_id']['label'] = 'registration state';
  /* Field: Ticket type: Host entity */
  $handler->display->display_options['fields']['entity']['id'] = 'entity';
  $handler->display->display_options['fields']['entity']['table'] = 'ticket_type';
  $handler->display->display_options['fields']['entity']['field'] = 'entity';
  $handler->display->display_options['fields']['entity']['relationship'] = 'ticket_type_ttid';
  $handler->display->display_options['fields']['entity']['label'] = 'Event';
  /* Field: Ticket type: Ticket type */
  $handler->display->display_options['fields']['ticket_type_label']['id'] = 'ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['table'] = 'field_data_ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['field'] = 'ticket_type_label';
  $handler->display->display_options['fields']['ticket_type_label']['relationship'] = 'ticket_type_ttid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Attendee';
  /* Field: Ticket registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Ticket registration: Link */
  $handler->display->display_options['fields']['view_registration']['id'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['view_registration']['field'] = 'view_registration';
  $handler->display->display_options['fields']['view_registration']['label'] = 'Operations';
  /* Field: Ticket registration: Edit link */
  $handler->display->display_options['fields']['edit_registration']['id'] = 'edit_registration';
  $handler->display->display_options['fields']['edit_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['edit_registration']['field'] = 'edit_registration';
  /* Field: Ticket registration: Cancel link */
  $handler->display->display_options['fields']['cancel_registration']['id'] = 'cancel_registration';
  $handler->display->display_options['fields']['cancel_registration']['table'] = 'ticket_registration';
  $handler->display->display_options['fields']['cancel_registration']['field'] = 'cancel_registration';
  /* Contextual filter: Ticket registration: Author_uid */
  $handler->display->display_options['arguments']['author_uid']['id'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['table'] = 'ticket_registration';
  $handler->display->display_options['arguments']['author_uid']['field'] = 'author_uid';
  $handler->display->display_options['arguments']['author_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['author_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['author_uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['author_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['author_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['author_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Ticket registration state: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'ticket_state';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'ticket_state_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['value'] = 'completed';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['display_description'] = 'Recent tickets registered by a user.';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'All tickets registered by a user.';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'user/%/tickets/registrant';

  $export['ticket_user'] = $view;

  return $export;
}
